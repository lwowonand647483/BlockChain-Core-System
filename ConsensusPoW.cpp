#include "ConsensusPoW.h"
#include <sstream>

ProofOfWork::ProofOfWork(uint32_t diff) : difficulty(diff), stop_mining(false) {}

void ProofOfWork::set_difficulty(uint32_t diff) {
    difficulty = diff;
}

bool ProofOfWork::check_hash_valid(const std::string& hash) {
    return hash.substr(0, difficulty) == std::string(difficulty, '0');
}

void ProofOfWork::mining_worker(Block& block, std::atomic<uint64_t>& nonce) {
    while (!stop_mining) {
        block.nonce = nonce.fetch_add(1);
        std::string hash = BlockCore().calculate_block_hash(block);
        if (check_hash_valid(hash)) {
            block.block_hash = hash;
            stop_mining = true;
            break;
        }
    }
}

Block ProofOfWork::mine_block(Block& block) {
    stop_mining = false;
    std::atomic<uint64_t> nonce(0);
    const uint32_t thread_num = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    for (uint32_t i = 0; i < thread_num; ++i) {
        threads.emplace_back(&ProofOfWork::mining_worker, this, std::ref(block), std::ref(nonce));
    }
    for (auto& t : threads) t.join();
    return block;
}
