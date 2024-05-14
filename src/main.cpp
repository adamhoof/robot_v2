#include <Arduino.h>
#include "SPI.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();

const uint8_t left_eye_up_down_comp = 0;
const uint16_t left_eye_up_down_max = 1200;
const uint16_t left_eye_up_down_center = 1450;
const uint16_t left_eye_up_down_min = 1750;
uint16_t left_eye_up_down_pos = left_eye_up_down_center;

const uint8_t right_eye_up_down_comp = 2;
const uint16_t right_eye_up_down_max = 1750;
const uint16_t right_eye_up_down_center = 1450;
const uint16_t right_eye_up_down_min = 1200;
uint16_t right_eye_up_down_pos = right_eye_up_down_center;

const uint8_t left_eye_left_right_comp = 1;
const uint16_t left_eye_left_right_right_most = 1100;
const uint16_t left_eye_left_right_center = 1450;
const uint16_t left_eye_left_right_left_most = 1800;
const uint16_t left_eye_left_right_pos = left_eye_left_right_center;

const uint8_t right_eye_left_right_comp = 3;
const uint16_t right_eye_left_right_right_most = 1800;
const uint16_t right_eye_left_right_center = 1450;
const uint16_t right_eye_left_right_left_most = 1100;
const uint16_t right_eye_left_right_pos = left_eye_left_right_center;

const uint16_t both_eyes_up_down_max = 1750;
const uint16_t both_eyes_up_down_center = 1450;
const uint16_t both_eyes_up_down_min = 1200;

const uint8_t left_koutek_bottom_comp = 4;
const uint8_t left_koutek_top_comp = 5;
struct left_koutek{
    uint16_t bottom_part_smile_max = 1700;
    uint16_t bottom_part_center = 1450;
    uint16_t bottom_part_pos = bottom_part_center;

    uint16_t top_part_smile_max = 2000;
    uint16_t top_part_center = 1450;
    uint16_t top_part_pos = top_part_center;
};

const uint8_t right_koutek_bottom_comp = 6;
const uint8_t right_koutek_top_comp = 7;
struct right_koutek{
    uint16_t bottom_part_smile_max = 1200;
    uint16_t bottom_part_center = 1450;
    uint16_t bottom_part_pos = bottom_part_center;

    uint16_t top_part_smile_max = 600;
    uint16_t top_part_center = 1450;
    uint16_t top_part_pos = top_part_center;
};

struct left_koutek leftKoutek;
struct right_koutek rightKoutek;

const long SERVOMIN = 125;
const long SERVOMAX = 600;

long msToPulse(uint16_t ms)
{
    return map(ms, 500, 2500, SERVOMIN, SERVOMAX);
}

void moveByMs(uint8_t part, uint16_t ms)
{
    driver.setPWM(part, 0, msToPulse(ms));
}

void moveLeftEyeUpDown(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target > left_eye_up_down_min || target < left_eye_up_down_max || stepSize == 0) {
        return;
    }

    if (target > left_eye_up_down_pos) {
        for (; target >= left_eye_up_down_pos; left_eye_up_down_pos += stepSize) {
            moveByMs(left_eye_up_down_comp, left_eye_up_down_pos);
            delay(delay_ms);
        }
    } else {
        for (; target <= left_eye_up_down_pos; left_eye_up_down_pos -= stepSize) {
            moveByMs(left_eye_up_down_comp, left_eye_up_down_pos);
            delay(delay_ms);
        }
    }
}

void moveRightEyeUpDown(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target < right_eye_up_down_min || target > right_eye_up_down_max || stepSize == 0) {
        return;
    }

    if (target > right_eye_up_down_pos) {
        for (; target >= right_eye_up_down_pos; right_eye_up_down_pos += stepSize) {
            moveByMs(right_eye_up_down_comp, right_eye_up_down_pos);
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_up_down_pos; right_eye_up_down_pos -= stepSize) {
            moveByMs(right_eye_up_down_comp, right_eye_up_down_pos);
            delay(delay_ms);
        }
    }
}

void moveLeftEyeLeftRight(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{

}


// Function to synchronize both eyes moving up and down
void moveBothEyesUpDownSync(uint16_t target, uint16_t delay_ms, uint16_t stepSize) {
    if (stepSize == 0) {
        return;  // Prevent zero division error with step size
    }
    const uint16_t RIGHT_EYE_RANGE_SUM = right_eye_up_down_max + right_eye_up_down_min;  // 1750 + 1200
    const uint16_t LEFT_EYE_RANGE_SUM = left_eye_up_down_max + left_eye_up_down_min;

    if (target > right_eye_up_down_pos) {
        for (; target >= right_eye_up_down_pos; right_eye_up_down_pos += stepSize) {
            moveByMs(right_eye_up_down_comp, right_eye_up_down_pos); // Move right eye
            left_eye_up_down_pos = LEFT_EYE_RANGE_SUM - right_eye_up_down_pos;  // Calculate left eye position
            moveByMs(left_eye_up_down_comp, left_eye_up_down_pos); // Move left eye
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_up_down_pos; right_eye_up_down_pos -= stepSize) {
            moveByMs(right_eye_up_down_comp, right_eye_up_down_pos); // Move right eye
            left_eye_up_down_pos = LEFT_EYE_RANGE_SUM - right_eye_up_down_pos;  // Calculate left eye position
            moveByMs(left_eye_up_down_comp, left_eye_up_down_pos); // Move left eye
            delay(delay_ms);
        }
    }
}

void moveBothKouteksToSmileMax(uint16_t delay_ms, uint16_t stepSize) {
    // Calculate the step increments for moving to the smile max position
    int stepsLeftBottom = (leftKoutek.bottom_part_smile_max - leftKoutek.bottom_part_pos) / stepSize;
    int stepsLeftTop = (leftKoutek.top_part_smile_max - leftKoutek.top_part_pos) / stepSize;
    int stepsRightBottom = (rightKoutek.bottom_part_smile_max - rightKoutek.bottom_part_pos) / stepSize;
    int stepsRightTop = (rightKoutek.top_part_smile_max - rightKoutek.top_part_pos) / stepSize;

    // Handle movement for each component
    for (int step = 0; step < abs(stepsLeftBottom); step++) {
        leftKoutek.bottom_part_pos += (stepsLeftBottom > 0 ? stepSize : -stepSize);
        leftKoutek.top_part_pos += (stepsLeftTop > 0 ? stepSize : -stepSize);
        rightKoutek.bottom_part_pos += (stepsRightBottom > 0 ? stepSize : -stepSize);
        rightKoutek.top_part_pos += (stepsRightTop > 0 ? stepSize : -stepSize);

        // Apply the movement
        moveByMs(left_koutek_bottom_comp, leftKoutek.bottom_part_pos);
        moveByMs(left_koutek_top_comp, leftKoutek.top_part_pos);
        moveByMs(right_koutek_bottom_comp, rightKoutek.bottom_part_pos);
        moveByMs(right_koutek_top_comp, rightKoutek.top_part_pos);

        // Delay between steps
        delay(delay_ms);
    }

    // Ensure all servos are set to the exact max smile position at the end
    moveByMs(left_koutek_bottom_comp, leftKoutek.bottom_part_smile_max);
    moveByMs(left_koutek_top_comp, leftKoutek.top_part_smile_max);
    moveByMs(right_koutek_bottom_comp, rightKoutek.bottom_part_smile_max);
    moveByMs(right_koutek_top_comp, rightKoutek.top_part_smile_max);
}

void moveBothKouteksToFrownMax(uint16_t delay_ms, uint16_t stepSize) {
    // Calculate the number of steps each koutek part needs to reach its smile max
    int stepsLeftBottom = abs(leftKoutek.bottom_part_smile_max - leftKoutek.bottom_part_pos) / stepSize;
    int stepsLeftTop = abs(leftKoutek.top_part_smile_max - leftKoutek.top_part_pos) / stepSize;
    int stepsRightBottom = abs(rightKoutek.bottom_part_smile_max - rightKoutek.bottom_part_pos) / stepSize;
    int stepsRightTop = abs(rightKoutek.top_part_smile_max - rightKoutek.top_part_pos) / stepSize;

    // Find the maximum steps needed to synchronize the movements
    int maxSteps = max(max(stepsLeftBottom, stepsLeftTop), max(stepsRightBottom, stepsRightTop));

    // Calculate the actual step sizes for each movement to synchronize the end point
    float stepLeftBottom = (float)(leftKoutek.bottom_part_smile_max - leftKoutek.bottom_part_pos) / maxSteps;
    float stepLeftTop = (float)(leftKoutek.top_part_smile_max - leftKoutek.top_part_pos) / maxSteps;
    float stepRightBottom = (float)(rightKoutek.bottom_part_smile_max - rightKoutek.bottom_part_pos) / maxSteps;
    float stepRightTop = (float)(rightKoutek.top_part_smile_max - rightKoutek.top_part_pos) / maxSteps;

    for (int i = 0; i < maxSteps; i++) {
        // Incrementally move each part towards its target
        leftKoutek.bottom_part_pos += stepLeftBottom;
        leftKoutek.top_part_pos += stepLeftTop;
        rightKoutek.bottom_part_pos += stepRightBottom;
        rightKoutek.top_part_pos += stepRightTop;

        // Apply the movement
        moveByMs(left_koutek_bottom_comp, (uint16_t)(leftKoutek.bottom_part_pos));
        moveByMs(left_koutek_top_comp, (uint16_t)(leftKoutek.top_part_pos));
        moveByMs(right_koutek_bottom_comp, (uint16_t)(rightKoutek.bottom_part_pos));
        moveByMs(right_koutek_top_comp, (uint16_t)(rightKoutek.top_part_pos));

        // Delay between steps
        delay(delay_ms);
    }

    // Ensure all servos are set to the exact max smile position at the end
    moveByMs(left_koutek_bottom_comp, leftKoutek.bottom_part_smile_max);
    moveByMs(left_koutek_top_comp, leftKoutek.top_part_smile_max);
    moveByMs(right_koutek_bottom_comp, rightKoutek.bottom_part_smile_max);
    moveByMs(right_koutek_top_comp, rightKoutek.top_part_smile_max);
}



void setup()
{
    Serial.begin(115200);
    Serial.println("Hello Borld");

    driver.begin();
    driver.setPWMFreq(60);

    /*moveLeftEyeUpDown(left_eye_left_right_center, 0, 1);
    moveRightEyeUpDown(right_eye_up_down_center, 0, 1);*/

    moveByMs(left_koutek_bottom_comp, leftKoutek.bottom_part_pos);
    moveByMs(left_koutek_top_comp, leftKoutek.top_part_pos);
    moveByMs(right_koutek_bottom_comp, rightKoutek.bottom_part_pos);
    moveByMs(right_koutek_top_comp, rightKoutek.top_part_pos);

    /*for (int i = 0; i <= 1200; ++i) {
        moveByMs(0,i);
    }*/
}

void loop()
{
    delay(500);
    moveBothKouteksToSmileMax(10,2);
    delay(500);
    moveByMs(left_koutek_bottom_comp, leftKoutek.bottom_part_pos);
    moveByMs(left_koutek_top_comp, leftKoutek.top_part_pos);
    moveByMs(right_koutek_bottom_comp, rightKoutek.bottom_part_pos);
    moveByMs(right_koutek_top_comp, rightKoutek.top_part_pos);
    /*moveBothEyesUpDownSync(both_eyes_up_down_max, 0,1);
    delay(1500);
    moveBothEyesUpDownSync(both_eyes_up_down_min, 0,1);
    delay(1500);*/
}