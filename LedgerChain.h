#ifndef LEDGER_CHAIN_H
#define LEDGER_CHAIN_H

#include "BlockCore.h"
#include <vector>
#include <mutex>

class BlockchainLedger {
public:
    static BlockchainLedger& get_instance();
    bool add_block(const Block& block);
    Block get_last_block();
    size_t get_chain_height();
    bool validate_chain();
    std::vector<Block> get_chain();

private:
    BlockchainLedger();
    std::vector<Block> chain;
    std::mutex mtx;
    BlockCore core;
};

#endif
