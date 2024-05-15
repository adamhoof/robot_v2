#include <Arduino.h>
#include "SPI.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();


struct left_eye_up_down {
    const uint8_t comp = 0;
    const uint16_t max = 1200;
    const uint16_t center = 1450;
    const uint16_t min = 1750;
    uint16_t pos = center;
};

left_eye_up_down left_eye_up_down;

struct right_eye_up_down {
    const uint8_t comp = 2;
    const uint16_t max = 1750;
    const uint16_t center = 1450;
    const uint16_t min = 1200;
    uint16_t pos = center;
};

right_eye_up_down right_eye_up_down;

struct left_eye_left_right {
    const uint8_t comp = 1;
    const uint16_t right_most = 1100;
    const uint16_t center = 1450;
    const uint16_t left_most = 1800;
    const uint16_t pos = center;
};

left_eye_left_right left_eye_left_right;

struct right_eye_left_right {
    const uint8_t comp = 3;
    const uint16_t right_most = 1800;
    const uint16_t center = 1450;
    const uint16_t left_most = 1100;
    const uint16_t pos = center;
};

right_eye_left_right right_eye_left_right;


struct both_eyes_up_down {
    const uint16_t max = 1750;
    const uint16_t center = 1450;
    const uint16_t min = 1200;
};

both_eyes_up_down both_eyes_up_down;


struct left_koutek {
    const uint8_t bottom_comp = 4;
    const uint8_t top_comp = 5;
    uint16_t bottom_part_smile_max = 1700;
    uint16_t bottom_part_center = 1450;
    uint16_t bottom_comp_pos = bottom_part_center;

    uint16_t top_part_smile_max = 2000;
    uint16_t top_part_center = 1450;
    uint16_t top_comp_pos = top_part_center;
};
struct left_koutek leftKoutek;


struct right_koutek {
    const uint8_t bottom_comp = 6;
    const uint8_t top_comp = 7;
    uint16_t bottom_part_smile_max = 1200;
    uint16_t bottom_part_center = 1450;
    uint16_t bottom_comp_pos = bottom_part_center;

    uint16_t top_part_smile_max = 600;
    uint16_t top_part_center = 1450;
    uint16_t top_comp_pos = top_part_center;
};

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
    if (target > left_eye_up_down.min || target < left_eye_up_down.max || stepSize == 0) {
        return;
    }

    if (target > left_eye_up_down.pos) {
        for (; target >= left_eye_up_down.pos; left_eye_up_down.pos += stepSize) {
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos);
            delay(delay_ms);
        }
    } else {
        for (; target <= left_eye_up_down.pos; left_eye_up_down.pos -= stepSize) {
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos);
            delay(delay_ms);
        }
    }
}

void moveRightEyeUpDown(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target < right_eye_up_down.min || target > right_eye_up_down.max || stepSize == 0) {
        return;
    }

    if (target > right_eye_up_down.pos) {
        for (; target >= right_eye_up_down.pos; right_eye_up_down.pos += stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos);
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_up_down.pos; right_eye_up_down.pos -= stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos);
            delay(delay_ms);
        }
    }
}

void moveLeftEyeLeftRight(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{

}


// Function to synchronize both eyes moving up and down
void moveBothEyesUpDownSync(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (stepSize == 0) {
        return;  // Prevent zero division error with step size
    }
    const uint16_t RIGHT_EYE_RANGE_SUM = right_eye_up_down.max + right_eye_up_down.min;  // 1750 + 1200
    const uint16_t LEFT_EYE_RANGE_SUM = left_eye_up_down.max + left_eye_up_down.min;

    if (target > right_eye_up_down.pos) {
        for (; target >= right_eye_up_down.pos; right_eye_up_down.pos += stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos); // Move right eye
            left_eye_up_down.pos = LEFT_EYE_RANGE_SUM - right_eye_up_down.pos;  // Calculate left eye position
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos); // Move left eye
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_up_down.pos; right_eye_up_down.pos -= stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos); // Move right eye
            left_eye_up_down.pos = LEFT_EYE_RANGE_SUM - right_eye_up_down.pos;  // Calculate left eye position
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos); // Move left eye
            delay(delay_ms);
        }
    }
}

void moveBothKouteksToSmileMax(uint16_t delay_ms, uint16_t stepSize)
{
    // Calculate the step increments for moving to the smile max position
    int stepsLeftBottom = (leftKoutek.bottom_part_smile_max - leftKoutek.bottom_comp_pos) / stepSize;
    int stepsLeftTop = (leftKoutek.top_part_smile_max - leftKoutek.top_comp_pos) / stepSize;
    int stepsRightBottom = (rightKoutek.bottom_part_smile_max - rightKoutek.bottom_comp_pos) / stepSize;
    int stepsRightTop = (rightKoutek.top_part_smile_max - rightKoutek.top_comp_pos) / stepSize;

    // Handle movement for each component
    for (int step = 0; step < abs(stepsLeftBottom); step++) {
        leftKoutek.bottom_comp_pos += (stepsLeftBottom > 0 ? stepSize : -stepSize);
        leftKoutek.top_comp_pos += (stepsLeftTop > 0 ? stepSize : -stepSize);
        rightKoutek.bottom_comp_pos += (stepsRightBottom > 0 ? stepSize : -stepSize);
        rightKoutek.top_comp_pos += (stepsRightTop > 0 ? stepSize : -stepSize);

        // Apply the movement
        moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_comp_pos);
        moveByMs(leftKoutek.top_comp, leftKoutek.top_comp_pos);
        moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_comp_pos);
        moveByMs(rightKoutek.top_comp, rightKoutek.top_comp_pos);

        // Delay between steps
        delay(delay_ms);
    }

    // Ensure all servos are set to the exact max smile position at the end
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_part_smile_max);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_part_smile_max);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_part_smile_max);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_part_smile_max);
}

void moveBothKouteksToFrownMax(uint16_t delay_ms, uint16_t stepSize)
{
    // Calculate the number of steps each koutek part needs to reach its smile max
    int stepsLeftBottom = abs(leftKoutek.bottom_part_smile_max - leftKoutek.bottom_comp_pos) / stepSize;
    int stepsLeftTop = abs(leftKoutek.top_part_smile_max - leftKoutek.top_comp_pos) / stepSize;
    int stepsRightBottom = abs(rightKoutek.bottom_part_smile_max - rightKoutek.bottom_comp_pos) / stepSize;
    int stepsRightTop = abs(rightKoutek.top_part_smile_max - rightKoutek.top_comp_pos) / stepSize;

    // Find the maximum steps needed to synchronize the movements
    int maxSteps = max(max(stepsLeftBottom, stepsLeftTop), max(stepsRightBottom, stepsRightTop));

    // Calculate the actual step sizes for each movement to synchronize the end point
    float stepLeftBottom = (float) (leftKoutek.bottom_part_smile_max - leftKoutek.bottom_comp_pos) / maxSteps;
    float stepLeftTop = (float) (leftKoutek.top_part_smile_max - leftKoutek.top_comp_pos) / maxSteps;
    float stepRightBottom = (float) (rightKoutek.bottom_part_smile_max - rightKoutek.bottom_comp_pos) / maxSteps;
    float stepRightTop = (float) (rightKoutek.top_part_smile_max - rightKoutek.top_comp_pos) / maxSteps;

    for (int i = 0; i < maxSteps; i++) {
        // Incrementally move each part towards its target
        leftKoutek.bottom_comp_pos += stepLeftBottom;
        leftKoutek.top_comp_pos += stepLeftTop;
        rightKoutek.bottom_comp_pos += stepRightBottom;
        rightKoutek.top_comp_pos += stepRightTop;

        // Apply the movement
        moveByMs(leftKoutek.bottom_comp, (uint16_t) (leftKoutek.bottom_comp_pos));
        moveByMs(leftKoutek.top_comp, (uint16_t) (leftKoutek.top_comp_pos));
        moveByMs(rightKoutek.bottom_comp, (uint16_t) (rightKoutek.bottom_comp_pos));
        moveByMs(rightKoutek.top_comp, (uint16_t) (rightKoutek.top_comp_pos));

        // Delay between steps
        delay(delay_ms);
    }

    // Ensure all servos are set to the exact max smile position at the end
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_part_smile_max);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_part_smile_max);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_part_smile_max);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_part_smile_max);
}


void setup()
{
    Serial.begin(115200);
    Serial.println("Hello Borld");

    driver.begin();
    driver.setPWMFreq(60);

    /*moveLeftEyeUpDown(left_eye_left_right_center, 0, 1);
    moveRightEyeUpDown(right_eye_up_down_center, 0, 1);*/

    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_comp_pos);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_comp_pos);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_comp_pos);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_comp_pos);

    /*for (int i = 0; i <= 1200; ++i) {
        moveByMs(0,i);
    }*/
}

void loop()
{
    delay(500);
    moveBothKouteksToSmileMax(10, 2);
    delay(500);
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_comp_pos);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_comp_pos);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_comp_pos);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_comp_pos);
    /*moveBothEyesUpDownSync(max, 0,1);
    delay(1500);
    moveBothEyesUpDownSync(min, 0,1);
    delay(1500);*/
}