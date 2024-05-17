#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdlib.h>

extern Adafruit_PWMServoDriver driver0;
extern Adafruit_PWMServoDriver driver1;

const long SERVOMIN = 125;
const long SERVOMAX = 600;

void setupDrivers();

long msToPulse(uint16_t ms);

void move_to(uint8_t part, uint16_t ms, uint8_t driverNum);
