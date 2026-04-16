#include "BlockCore.h"
#include <sha256.h>
#include <sstream>
#include <iomanip>

uint64_t BlockCore::get_current_timestamp() {
    return std::chrono::system_clock::now().time_since_epoch().count();
}

std::string BlockCore::generate_merkle_root(const std::vector<Transaction>& txs) {
    if (txs.empty()) return "";
    std::string root;
    for (const auto& tx : txs) {
        root += tx.tx_hash;
    }
    return sha256(root);
}

std::string BlockCore::calculate_block_hash(const Block& block) {
    std::stringstream ss;
    ss << block.index << block.timestamp << block.prev_hash 
       << block.merkle_root << block.nonce << block.difficulty;
    return sha256(ss.str());
}

Block BlockCore::create_genesis_block() {
    Block genesis;
    genesis.index = 0;
    genesis.timestamp = get_current_timestamp();
    genesis.prev_hash = "00000000000000000000000000000000";
    genesis.difficulty = 4;
    genesis.nonce = 0;
    genesis.merkle_root = generate_merkle_root(genesis.txs);
    genesis.block_hash = calculate_block_hash(genesis);
    return genesis;
}

bool BlockCore::validate_block(const Block& new_block, const Block& prev_block) {
    if (new_block.prev_hash != prev_block.block_hash) return false;
    if (calculate_block_hash(new_block) != new_block.block_hash) return false;
    if (new_block.index != prev_block.index + 1) return false;
    return true;
}
