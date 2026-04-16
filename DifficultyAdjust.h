#ifndef DIFFICULTY_ADJUST_H
#define DIFFICULTY_ADJUST_H

#include "BlockCore.h"
#include <vector>
#include <cstdint>

class DifficultyAdjuster {
public:
    explicit DifficultyAdjuster(uint32_t target_block_time);
    uint32_t calculate_new_difficulty(const std::vector<Block>& window);
    
private:
    uint32_t target_time;
    uint64_t get_window_time(const std::vector<Block>& window);
};

#endif
