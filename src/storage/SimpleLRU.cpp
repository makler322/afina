#include "SimpleLRU.h"
#include <iostream>
#include <cassert>
namespace Afina {
namespace Backend {

void SimpleLRU::AllocateMemory(const std::string &key, const std::string &value, const std::string &old_value=""){ 
    assert (key.size() + value.size() <= _max_size);
    lru_node* object = _lru_tail;
    std::size_t new_size = 0;
    if (old_value.size() > 0){
        if (value.size() > old_value.size()){
            new_size = value.size() - old_value.size();
        } else {
            return;
        }
    } else {
        new_size = value.size() + key.size();
    }
    while (_cur_size + new_size > _max_size) {
        _lru_tail = object->prev;
        _lru_index.erase(object->key);
        _cur_size -= (object->key.size() + object->value.size());
        object = object->prev;				
        object->next.reset();
    }
    return;
}
  
void SimpleLRU::Move2Head(lru_node* object) {
    if (object == _lru_head.get()){
        return;
    }
    if (object == _lru_tail){
        _lru_tail = _lru_tail->prev;
    }
    auto cur_node = std::move(object->prev->next);
    object->prev->next = std::move(cur_node->next);
    _lru_head->prev = object;
    cur_node->next =std::move(_lru_head);
    _lru_head = std::move(cur_node);
}

void SimpleLRU::Put2Head(const std::string &key, const std::string &value) {
    lru_node* object = new lru_node{key, value, nullptr, std::move(_lru_head)};
    _lru_head = std::unique_ptr<lru_node>(object);
    if (!_lru_tail) {
        _lru_tail = object;
    } else {
        object->next.get()->prev = object;
    }
    _lru_index.emplace(std::make_pair(std::ref(object->key), std::ref(*object)));
    _cur_size += (key.size() + value.size());
}


bool SimpleLRU::NodeUpdate(lru_node *object, const std::string &value){
    if (object -> key.size() + value.size() > _max_size){
        return false;
    }
    Move2Head(object);
    AllocateMemory(object -> key, value, object -> value);
    _cur_size = _cur_size - (object -> value).size() + value.size();
    object -> value = value;
    return true;
}

void SimpleLRU::NodeDelete(lru_node *object){
    if (object == _lru_head.get()){
        return;
    }
    if (object == _lru_tail){
        _lru_tail = _lru_tail->prev;
    }
    auto cur_node = std::move(object->prev->next);
    object->prev->next = std::move(cur_node->next);
    _cur_size -= (object->key.size() + object->value.size());
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Put(const std::string &key, const std::string &value) {
    if (key.size() + value.size() > _max_size){
        return false;
    }
    auto cur_node = _lru_index.find(std::ref(key));
    if (cur_node == _lru_index.end()) { 
        AllocateMemory(key, value);
        Put2Head(key, value);
        return true;
    }
    return NodeUpdate(&cur_node->second.get(), value);;
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::PutIfAbsent(const std::string &key, const std::string &value) {
    if (key.size() + value.size() > _max_size){
        return false;
    }
    auto cur_node = _lru_index.find(std::ref(key));
    if (cur_node != _lru_index.end()) {
        return false;
    }
    AllocateMemory(key, value);
    Put2Head(key, value);
    return true;
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Set(const std::string &key, const std::string &value) {
    if (key.size() + value.size() > _max_size){
        return false;
    }
    auto cur_node = _lru_index.find(std::ref(key));
    if (cur_node == _lru_index.end()) {
        return false;
    }
    return NodeUpdate(&cur_node->second.get(), value);
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Delete(const std::string &key) {
    auto index_node = _lru_index.find(std::ref(key));
    if (index_node == _lru_index.end()) { // If key not in map
        return false;
    }
    lru_node* object = &index_node->second.get();
    _lru_index.erase(index_node);
    NodeDelete(object);
    return true;
}

// See MapBasedGlobalLockImpl.h
bool SimpleLRU::Get(const std::string &key, std::string &value) {
    auto cur_node = _lru_index.find(std::ref(key));
    if (cur_node == _lru_index.end()) { // If key not in map
        return false;
    }
    value = cur_node->second.get().value;
    Move2Head(&cur_node->second.get());
    return true;
}

} // namespace Backend
} // namespace Afina
