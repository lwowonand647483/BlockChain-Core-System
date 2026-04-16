#ifndef CROSS_CHAIN_BRIDGE_H
#define CROSS_CHAIN_BRIDGE_H

#include <string>
#include <vector>
#include <unordered_map>

struct CrossChainTx {
    std::string source_chain;
    std::string target_chain;
    std::string sender;
    std::string receiver;
    double amount;
    std::string tx_id;
    bool locked;
};

class CrossChainBridge {
public:
    bool lock_asset(const CrossChainTx& tx);
    bool unlock_asset(const std::string& tx_id);
    CrossChainTx get_tx(const std::string& tx_id);
    std::vector<std::string> get_supported_chains();
    void add_chain(const std::string& chain);

private:
    std::unordered_map<std::string, CrossChainTx> txs;
    std::vector<std::string> chains;
};

#endif
