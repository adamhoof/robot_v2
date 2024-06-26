#pragma once

#include <Arduino.h>
#include "driver.h"

class TopToothCenter {
private:
    const uint8_t driver_num = 0;
    const uint8_t part = 5;
    const uint16_t center = 1450;
    const uint16_t up_most = 1700;
    uint16_t pos = 0;
public:
    void move_center();

    void move_up_most();

    void move_up_by(uint16_t moveBy);

    void move_down_by(uint16_t moveBy);

    void move_down_most();
};
