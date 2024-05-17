#pragma once

#include <Arduino.h>
#include "driver.h"

class LeftEyeUpDown {
private:
    uint16_t pos = 0;

public:
    const uint8_t driver_num = 1;
    const uint8_t comp = 1;
    const uint16_t up_most = 1650;
    const uint16_t center = 1450;
    const uint16_t down_most = 1250;

    void move_center();
    void move_up_most();
    void move_down_most();
    void move_up_by(uint16_t moveBy);
    void move_down_by(uint16_t moveBy);
};
