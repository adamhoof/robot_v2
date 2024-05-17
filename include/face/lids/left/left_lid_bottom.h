#pragma once
#include <Arduino.h>
#include "driver.h"

class LeftLidBottom {
private:
    const uint8_t driver_num = 1;
    const uint8_t part = 3;
    const uint16_t center = 1500;
    const uint16_t down_most = center;
    uint16_t pos = 0;
};
