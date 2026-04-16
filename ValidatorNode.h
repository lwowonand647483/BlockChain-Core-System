#ifndef VALIDATOR_NODE_H
#define VALIDATOR_NODE_H

#include "BlockCore.h"
#include "LedgerChain.h"
#include <string>

class Validator {
public:
    explicit Validator(const std::string& node_id);
    bool validate_block(const Block& block);
    bool vote_block(const Block& block);
    std::string get_node_id();
    uint64_t get_stake();
    void add_stake(uint64_t amount);

private:
    std::string node_id;
    uint64_t stake;
    BlockCore core;
};

#endif
