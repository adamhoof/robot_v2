#pragma once
#include <Arduino.h>
#include "driver.h"

class RightLidTop {
private:
    const uint8_t driver_num = 1;
    const uint8_t part = 7;
    const uint16_t center = 1550;
    const uint16_t down_most = center;
    const uint16_t up_most = 1200;
    uint16_t pos = 0;
public:
    void move_center();
    void move_up_most();
    void move_down_most();
    void move_up_by(uint16_t moveBy);
    void move_down_by(uint16_t moveBy);
};
