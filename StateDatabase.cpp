#include "StateDatabase.h"

void StateDB::set_value(const std::string& key, const std::string& value) {
    std::lock_guard<std::mutex> lock(mtx);
    db[key] = value;
}

std::string StateDB::get_value(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    auto it = db.find(key);
    return it != db.end() ? it->second : "";
}

bool StateDB::delete_key(const std::string& key) {
    std::lock_guard<std::mutex> lock(mtx);
    return db.erase(key) > 0;
}

void StateDB::clear_all() {
    std::lock_guard<std::mutex> lock(mtx);
    db.clear();
}

size_t StateDB::get_key_count() {
    std::lock_guard<std::mutex> lock(mtx);
    return db.size();
}
