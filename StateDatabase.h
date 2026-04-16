#ifndef STATE_DATABASE_H
#define STATE_DATABASE_H

#include <string>
#include <unordered_map>
#include <mutex>

class StateDB {
public:
    void set_value(const std::string& key, const std::string& value);
    std::string get_value(const std::string& key);
    bool delete_key(const std::string& key);
    void clear_all();
    size_t get_key_count();

private:
    std::unordered_map<std::string, std::string> db;
    std::mutex mtx;
};

#endif
