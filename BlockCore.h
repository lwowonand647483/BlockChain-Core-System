#ifndef BLOCK_CORE_H
#define BLOCK_CORE_H

#include <string>
#include <vector>
#include <chrono>
#include <cstdint>

struct Transaction {
    std::string sender;
    std::string receiver;
    double amount;
    uint64_t timestamp;
    std::string tx_hash;
};

struct Block {
    uint32_t index;
    uint64_t timestamp;
    std::string prev_hash;
    std::string merkle_root;
    std::vector<Transaction> txs;
    uint64_t nonce;
    uint32_t difficulty;
    std::string block_hash;
};

class BlockCore {
public:
    Block create_genesis_block();
    std::string calculate_block_hash(const Block& block);
    bool validate_block(const Block& new_block, const Block& prev_block);
    
private:
    std::string generate_merkle_root(const std::vector<Transaction>& txs);
    uint64_t get_current_timestamp();
};

#endif
