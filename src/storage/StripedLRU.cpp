#include "storage/StripedLRU.h"
//#include <spdlog/logger.h>

namespace Afina {
namespace Backend {

std::unique_ptr<StripedLRU> StripedLRU::BuildStripedLRU(std::size_t memory_limit, std::size_t stripe_count) {
    if (memory_limit / stripe_count <= MEGABYTE) {
        throw std::invalid_argument("Not enough memory for stripped storage");
    }
    return std::unique_ptr<StripedLRU>(new StripedLRU(memory_limit, stripe_count));
}

StripedLRU::StripedLRU(std::size_t memory_limit, std::size_t stripe_count) {
    _stripe_limit = memory_limit / stripe_count;
    _stripe_count = stripe_count;

    for (int i = 0; i < _stripe_count; i++) {
        _shards.emplace_back(_stripe_limit);
    }
}

bool StripedLRU::Put(const std::string &key, const std::string &value) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Put(key, value);
}

bool StripedLRU::PutIfAbsent(const std::string &key, const std::string &value) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].PutIfAbsent(key, value);
}

bool StripedLRU::Set(const std::string &key, const std::string &value) {
    // DEBUG
    //_logger->debug("Got {} bytes from socket", key);
    //std::cout << "Set to " << std::hash<std::string>{}(key) % _stripe_count << std::endl;
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Set(key, value);
}

bool StripedLRU::Delete(const std::string &key) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Delete(key);
}

bool StripedLRU::Get(const std::string &key, std::string &value) {
    return _shards[std::hash<std::string>{}(key) % _stripe_count].Get(key, value);
}

} // namespace Backend
} // namespace Afina