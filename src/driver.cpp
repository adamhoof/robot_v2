#include "driver.h"

Adafruit_PWMServoDriver driver0 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver driver1 = Adafruit_PWMServoDriver(0x41);

void setupDrivers() {
    driver0.begin();
    driver0.setPWMFreq(60);
    driver1.begin();
    driver1.setPWMFreq(60);
}

long msToPulse(uint16_t ms) {
    return map(ms, 500, 2500, SERVOMIN, SERVOMAX);
}

void moveByMs(uint8_t part, uint16_t ms, uint8_t driverNum) {
    if (driverNum == 0) {
        driver0.setPWM(part, 0, msToPulse(ms));
    } else {
        driver1.setPWM(part, 0, msToPulse(ms));
    }
}
