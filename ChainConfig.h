#ifndef CHAIN_CONFIG_H
#define CHAIN_CONFIG_H

#include <string>
#include <cstdint>

struct ChainConfig {
    uint32_t block_time;
    uint32_t initial_difficulty;
    uint64_t max_block_size;
    uint64_t block_reward;
    std::string chain_name;
    std::string chain_symbol;
    bool enable_smart_contract;
    bool enable_p2p;
};

class ConfigLoader {
public:
    static ChainConfig load_default_config();
    static ChainConfig load_from_file(const std::string& path);
    static bool save_config(const ChainConfig& cfg, const std::string& path);
};

#endif
