#ifndef TX_POOL_H
#define TX_POOL_H

#include "BlockCore.h"
#include <vector>
#include <mutex>
#include <algorithm>

class TransactionPool {
public:
    bool add_transaction(const Transaction& tx);
    bool remove_transaction(const std::string& tx_hash);
    std::vector<Transaction> get_pending_txs(size_t limit);
    size_t get_pool_size();
    void clear();

private:
    std::vector<Transaction> pool;
    std::mutex mtx;
    bool tx_exists(const std::string& tx_hash);
};

#endif
