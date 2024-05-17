#pragma once
#include <Arduino.h>

class RightKoutek {
private:
    const uint8_t driver_num = 0;
    const uint8_t bottom_comp = 2;
    const uint8_t top_comp = 3;
public:
    uint16_t bottom_part_smile_most = 1200;
    uint16_t bottom_part_center = 1450;
    uint16_t bottom_comp_pos = bottom_part_center;

    uint16_t top_part_up_most = 600;
    uint16_t top_part_center = 1450;
    uint16_t top_comp_pos = top_part_center;
};

