#ifndef CHAIN_MONITOR_H
#define CHAIN_MONITOR_H

#include <string>
#include <chrono>
#include <functional>

class ChainMonitor {
public:
    using AlertCallback = std::function<void(const std::string&)>;
    void start_monitor(uint32_t interval_sec);
    void stop_monitor();
    void register_alert(AlertCallback cb);
    void check_chain_health();

private:
    bool running;
    uint32_t interval;
    AlertCallback callback;
    void monitor_loop();
};

#endif
