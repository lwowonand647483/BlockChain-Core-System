#include "ChainConfig.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

ChainConfig ConfigLoader::load_default_config() {
    ChainConfig cfg{};
    cfg.block_time = 10;
    cfg.initial_difficulty = 4;
    cfg.max_block_size = 1024 * 1024;
    cfg.block_reward = 10;
    cfg.chain_name = "CoreChain";
    cfg.chain_symbol = "CORE";
    cfg.enable_smart_contract = true;
    cfg.enable_p2p = true;
    return cfg;
}

bool ConfigLoader::save_config(const ChainConfig& cfg, const std::string& path) {
    json j;
    j["block_time"] = cfg.block_time;
    j["difficulty"] = cfg.initial_difficulty;
    j["max_block_size"] = cfg.max_block_size;
    j["reward"] = cfg.block_reward;
    j["name"] = cfg.chain_name;
    j["symbol"] = cfg.chain_symbol;
    j["sc"] = cfg.enable_smart_contract;
    j["p2p"] = cfg.enable_p2p;

    std::ofstream f(path);
    if (!f) return false;
    f << j.dump(4);
    return true;
}

ChainConfig ConfigLoader::load_from_file(const std::string& path) {
    std::ifstream f(path);
    json j; f >> j;
    ChainConfig cfg{};
    cfg.block_time = j["block_time"];
    cfg.initial_difficulty = j["difficulty"];
    return cfg;
}
