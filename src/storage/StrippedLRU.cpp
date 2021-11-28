
#include "storage/StrippedLRU.h"
//#include <spdlog/logger.h>

namespace Afina {
namespace Backend {

std::unique_ptr<StrippedLRU> StrippedLRU::BuildStrippedLRU(std::size_t memory_limit, std::size_t stripe_count) {
    if (memory_limit / stripe_count <= MEGABYTE) {
        throw std::invalid_argument("Not enough memory for stripped storage");
    }
    return std::unique_ptr<StrippedLRU>(new StrippedLRU(memory_limit, stripe_count));
}

StrippedLRU::StrippedLRU(std::size_t memory_limit, std::size_t stripe_count) {
    _stripe_limit = memory_limit / stripe_count;
    _stripe_count = stripe_count;

    for (int i = 0; i < _stripe_count; i++) {
        _shards.emplace_back(_stripe_limit);
    }
}

bool StrippedLRU::Put(const std::string &key, const std::string &value) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Put(key, value);
}

bool StrippedLRU::PutIfAbsent(const std::string &key, const std::string &value) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].PutIfAbsent(key, value);
}

bool StrippedLRU::Set(const std::string &key, const std::string &value) {
    // DEBUG
    //_logger->debug("Got {} bytes from socket", key);
    //std::cout << "Set to " << std::hash<std::string>{}(key) % _stripe_count << std::endl;
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Set(key, value);
}

bool StrippedLRU::Delete(const std::string &key) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Delete(key);
}

bool StrippedLRU::Get(const std::string &key, std::string &value) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Get(key, value);
}

} // namespace Backend
} // namespace Afina