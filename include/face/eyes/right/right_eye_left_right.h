#pragma once

#include <Arduino.h>
#include "driver.h"

class RightEyeLeftRight {
private:
    uint16_t pos = 0;
public:
    const uint8_t driver_num = 1;
    const uint8_t comp = 5;
    const uint16_t right_most = 1540;
    const uint16_t center = 1400;
    const uint16_t left_most = 1240;

    void move_center();

    void move_left_most();

    void move_right_most();

    void move_right_by(uint16_t moveBy);

    void move_left_by(uint16_t moveBy);
};
