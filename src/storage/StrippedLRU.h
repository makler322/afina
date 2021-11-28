#ifndef AFINA_STORAGE_STRIPED_LRU_H
#define AFINA_STORAGE_STRIPED_LRU_H

#include <vector>
#include <string>

#include <afina/Storage.h>
#include "SimpleLRU.h"
#include "ThreadSafeSimpleLRU.h"

// 1 mb - protocol limit
constexpr std::size_t MEGABYTE = 1024 * 1024;

namespace spdlog {
    class logger;
}

namespace Afina {
namespace Backend {

class StrippedLRU : public Afina::Storage {
public:
    StrippedLRU() = default;
    ~StrippedLRU() = default;

    static std::unique_ptr<StrippedLRU> BuildStrippedLRU(std::size_t memory_limit, std::size_t stripe_count);

    // Implements Afina::Storage interface
    bool Put(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool PutIfAbsent(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool Set(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool Delete(const std::string &key) override;

    // Implements Afina::Storage interface
    bool Get(const std::string &key, std::string &value) override;

private:
    StrippedLRU(std::size_t memory_limit, std::size_t stripe_count);

    // Memory limit for each simple LRU
    size_t _stripe_limit;

    // Count of simple LRUs
    uint32_t _stripe_count;

    // Simple LRUs
    std::vector<SimpleLRU> _shards;
};

} // namespace Backend
} // namespace Afina

#endif // AFINA_STORAGE_STRIPED_LRU_H