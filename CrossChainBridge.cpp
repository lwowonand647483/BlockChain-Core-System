#include "CrossChainBridge.h"

void CrossChainBridge::add_chain(const std::string& chain) {
    chains.push_back(chain);
}

std::vector<std::string> CrossChainBridge::get_supported_chains() {
    return chains;
}

bool CrossChainBridge::lock_asset(const CrossChainTx& tx) {
    if (txs.count(tx.tx_id)) return false;
    CrossChainTx c = tx;
    c.locked = true;
    txs[tx.tx_id] = c;
    return true;
}

bool CrossChainBridge::unlock_asset(const std::string& tx_id) {
    if (!txs.count(tx_id)) return false;
    txs[tx_id].locked = false;
    return true;
}

CrossChainTx CrossChainBridge::get_tx(const std::string& tx_id) {
    return txs[tx_id];
}
