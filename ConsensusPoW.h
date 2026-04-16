#ifndef CONSENSUS_POW_H
#define CONSENSUS_POW_H

#include "BlockCore.h"
#include <atomic>
#include <thread>

class ProofOfWork {
public:
    explicit ProofOfWork(uint32_t diff);
    Block mine_block(Block& block);
    void set_difficulty(uint32_t diff);
    bool check_hash_valid(const std::string& hash);
    
private:
    uint32_t difficulty;
    std::atomic<bool> stop_mining;
    void mining_worker(Block& block, std::atomic<uint64_t>& nonce);
};

#endif
