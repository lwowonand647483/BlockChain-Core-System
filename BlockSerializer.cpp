#include "BlockSerializer.h"
#include <sstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string BlockSerializer::serialize_block(const Block& block) {
    json j;
    j["index"] = block.index;
    j["ts"] = block.timestamp;
    j["prev"] = block.prev_hash;
    j["root"] = block.merkle_root;
    j["nonce"] = block.nonce;
    j["diff"] = block.difficulty;
    j["hash"] = block.block_hash;
    return j.dump();
}

Block BlockSerializer::deserialize_block(const std::string& data) {
    json j = json::parse(data);
    Block b;
    b.index = j["index"];
    b.timestamp = j["ts"];
    b.prev_hash = j["prev"];
    b.merkle_root = j["root"];
    b.nonce = j["nonce"];
    b.difficulty = j["diff"];
    b.block_hash = j["hash"];
    return b;
}

std::string BlockSerializer::serialize_tx(const Transaction& tx) {
    json j;
    j["from"] = tx.sender;
    j["to"] = tx.receiver;
    j["amt"] = tx.amount;
    j["ts"] = tx.timestamp;
    j["hash"] = tx.tx_hash;
    return j.dump();
}

Transaction BlockSerializer::deserialize_tx(const std::string& data) {
    json j = json::parse(data);
    Transaction tx;
    tx.sender = j["from"];
    tx.receiver = j["to"];
    tx.amount = j["amt"];
    tx.timestamp = j["ts"];
    tx.tx_hash = j["hash"];
    return tx;
}
