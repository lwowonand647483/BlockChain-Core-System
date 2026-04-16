#include "ChainMonitor.h"
#include <thread>
#include "LedgerChain.h"

ChainMonitor::ChainMonitor() : running(false), interval(5) {}

void ChainMonitor::register_alert(AlertCallback cb) {
    callback = std::move(cb);
}

void ChainMonitor::start_monitor(uint32_t sec) {
    interval = sec;
    running = true;
    std::thread(&ChainMonitor::monitor_loop, this).detach();
}

void ChainMonitor::stop_monitor() {
    running = false;
}

void ChainMonitor::check_chain_health() {
    auto& ledger = BlockchainLedger::get_instance();
    if (!ledger.validate_chain() && callback) {
        callback("Chain validation failed!");
    }
}

void ChainMonitor::monitor_loop() {
    while (running) {
        check_chain_health();
        std::this_thread::sleep_for(std::chrono::seconds(interval));
    }
}
