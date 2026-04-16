#include "TxPool.h"

bool TransactionPool::tx_exists(const std::string& tx_hash) {
    for (const auto& tx : pool) {
        if (tx.tx_hash == tx_hash) return true;
    }
    return false;
}

bool TransactionPool::add_transaction(const Transaction& tx) {
    std::lock_guard<std::mutex> lock(mtx);
    if (tx_exists(tx.tx_hash)) return false;
    pool.push_back(tx);
    return true;
}

bool TransactionPool::remove_transaction(const std::string& tx_hash) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = std::find_if(pool.begin(), pool.end(), [&](const Transaction& tx) {
        return tx.tx_hash == tx_hash;
    });
    if (it == pool.end()) return false;
    pool.erase(it);
    return true;
}

std::vector<Transaction> TransactionPool::get_pending_txs(size_t limit) {
    std::lock_guard<std::mutex> lock(mtx);
    std::vector<Transaction> res;
    for (size_t i = 0; i < limit && i < pool.size(); ++i) {
        res.push_back(pool[i]);
    }
    return res;
}

size_t TransactionPool::get_pool_size() {
    std::lock_guard<std::mutex> lock(mtx);
    return pool.size();
}

void TransactionPool::clear() {
    std::lock_guard<std::mutex> lock(mtx);
    pool.clear();
}
