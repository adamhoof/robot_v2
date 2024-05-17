#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_PWMServoDriver.h>
#include <stdlib.h>

Adafruit_PWMServoDriver driver0 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver driver1 = Adafruit_PWMServoDriver(0x41);

const long SERVOMIN = 125;
const long SERVOMAX = 600;

void setupDrivers();

long msToPulse(uint16_t ms);

void moveByMs(uint8_t part, uint16_t ms, uint8_t driverNum);
