#include "LedgerChain.h"

BlockchainLedger::BlockchainLedger() {
    chain.push_back(core.create_genesis_block());
}

BlockchainLedger& BlockchainLedger::get_instance() {
    static BlockchainLedger instance;
    return instance;
}

bool BlockchainLedger::add_block(const Block& block) {
    std::lock_guard<std::mutex> lock(mtx);
    if (core.validate_block(block, get_last_block())) {
        chain.push_back(block);
        return true;
    }
    return false;
}

Block BlockchainLedger::get_last_block() {
    return chain.back();
}

size_t BlockchainLedger::get_chain_height() {
    return chain.size();
}

bool BlockchainLedger::validate_chain() {
    std::lock_guard<std::mutex> lock(mtx);
    for (size_t i = 1; i < chain.size(); ++i) {
        if (!core.validate_block(chain[i], chain[i-1])) return false;
    }
    return true;
}

std::vector<Block> BlockchainLedger::get_chain() {
    std::lock_guard<std::mutex> lock(mtx);
    return chain;
}
