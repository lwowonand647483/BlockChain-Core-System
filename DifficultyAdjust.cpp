#include "DifficultyAdjust.h"

DifficultyAdjuster::DifficultyAdjuster(uint32_t target) : target_time(target) {}

uint64_t DifficultyAdjuster::get_window_time(const std::vector<Block>& window) {
    if (window.size() < 2) return 0;
    return window.back().timestamp - window[0].timestamp;
}

uint32_t DifficultyAdjuster::calculate_new_difficulty(const std::vector<Block>& window) {
    uint64_t actual = get_window_time(window);
    uint32_t current = window.back().difficulty;
    if (actual == 0) return current;
    
    if (actual < target_time * 0.5) return current + 1;
    if (actual > target_time * 2) return current - 1;
    return current;
}
