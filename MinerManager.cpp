#include "MinerManager.h"

MinerManager::MinerManager() 
    : pow(4), mining(false), mined_count(0), miner_addr("miner_default") {}

void MinerManager::set_miner_address(const std::string& addr) {
    miner_addr = addr;
}

void MinerManager::start_mining() {
    mining = true;
    std::thread(&MinerManager::mining_loop, this).detach();
}

void MinerManager::stop_mining() {
    mining = false;
}

uint64_t MinerManager::get_mined_blocks() {
    return mined_count;
}

void MinerManager::mining_loop() {
    auto& ledger = BlockchainLedger::get_instance();
    auto& tx_pool = TransactionPool();
    while (mining) {
        Block block;
        block.index = ledger.get_chain_height();
        block.prev_hash = ledger.get_last_block().block_hash;
        block.txs = tx_pool.get_pending_txs(100);
        block.difficulty = 4;
        
        block = pow.mine_block(block);
        if (ledger.add_block(block)) {
            mined_count++;
            tx_pool.clear();
        }
    }
}
