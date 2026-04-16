#include "ValidatorNode.h"

Validator::Validator(const std::string& id) : node_id(id), stake(0) {}

bool Validator::validate_block(const Block& block) {
    auto& ledger = BlockchainLedger::get_instance();
    return core.validate_block(block, ledger.get_last_block());
}

bool Validator::vote_block(const Block& block) {
    if (stake == 0) return false;
    return validate_block(block);
}

std::string Validator::get_node_id() {
    return node_id;
}

uint64_t Validator::get_stake() {
    return stake;
}

void Validator::add_stake(uint64_t amount) {
    stake += amount;
}
