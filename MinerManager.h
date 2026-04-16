#ifndef MINER_MANAGER_H
#define MINER_MANAGER_H

#include "ConsensusPoW.h"
#include "LedgerChain.h"
#include "TxPool.h"
#include <thread>

class MinerManager {
public:
    MinerManager();
    void start_mining();
    void stop_mining();
    uint64_t get_mined_blocks();
    void set_miner_address(const std::string& addr);

private:
    ProofOfWork pow;
    bool mining;
    std::string miner_addr;
    uint64_t mined_count;
    void mining_loop();
};

#endif
