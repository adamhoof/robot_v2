#include <Arduino.h>
#include "driver.h"
#include "face/eyes/left/left_eye_left_right.h"
#include "face/eyes/left/left_eye_up_down.h"
#include "face/eyes/right/right_eye_left_right.h"
#include "face/eyes/right/right_eye_up_down.h"
#include "face/lids/left/left_lid_down.h"
#include "face/lids/left/left_lid_up.h"
#include "face/mouth/chin/chin.h"
#include "face/mouth/teeth/top/top_tooth_left.h"
#include "face/mouth/teeth/bottom/bottom_tooth_right.h"
#include "face/mouth/teeth/bottom/bottom_tooth_center.h"
#include "face/mouth/teeth/bottom/bottom_tooth_left.h"
#include "face/mouth/teeth/top/top_tooth_right.h"
#include "face/mouth/teeth/top/top_tooth_center.h"
#include "face/mouth/koutky/right/right_koutek.h"
#include "face/mouth/koutky/left/left_koutek.h"
#include "face/lids/right/right_lid_up.h"
#include "face/lids/right/right_lid_down.h"

LeftEyeUpDown left_eye_up_down;
RightEyeUpDown right_eye_up_down;
LeftEyeLeftRight left_eye_left_right;
RightEyeLeftRight right_eye_left_right;
LeftKoutek leftKoutek;
RightKoutek rightKoutek;
TopToothLeft topToothLeft;
TopToothCenter topToothCenter;
TopToothRight topToothRight;
BottomToothLeft downToothLeft;
BottomToothCenter downToothCenter;
BottomToothRight downToothRight;
LeftLidUp leftLidUp;
LeftLidDown leftLidDown;
RightLidUp rightLidUp;
RightLidDown rightLidDown;
Chin chin;

/*
void moveLeftEyeUpDown(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target > left_eye_up_down.down_most || target < left_eye_up_down.up_most || stepSize == 0) {
        return;
    }

    if (target > left_eye_up_down.pos) {
        for (; target >= left_eye_up_down.pos; left_eye_up_down.pos += stepSize) {
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos, left_eye_up_down.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= left_eye_up_down.pos; left_eye_up_down.pos -= stepSize) {
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos, left_eye_up_down.driver_num);
            delay(delay_ms);
        }
    }
}

void moveRightEyeUpDown(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target < right_eye_up_down.down_most || target > right_eye_up_down.up_most || stepSize == 0) {
        return;
    }

    if (target > right_eye_up_down.pos) {
        for (; target >= right_eye_up_down.pos; right_eye_up_down.pos += stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos, right_eye_up_down.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_up_down.pos; right_eye_up_down.pos -= stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos, right_eye_up_down.driver_num);
            delay(delay_ms);
        }
    }
}

void moveLeftEyeLeftRight(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target > left_eye_left_right.left_most || target < left_eye_left_right.right_most || stepSize == 0) {
        return;
    }

    if (target > left_eye_left_right.pos) {
        for (; target >= left_eye_left_right.pos; left_eye_left_right.pos += stepSize) {
            moveByMs(left_eye_left_right.comp, left_eye_left_right.pos, left_eye_left_right.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= left_eye_left_right.pos; left_eye_left_right.pos -= stepSize) {
            moveByMs(left_eye_left_right.comp, left_eye_left_right.pos, left_eye_left_right.driver_num);
            delay(delay_ms);
        }
    }
}

void moveRightEyeLeftRight(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target > right_eye_left_right.left_most || target < right_eye_left_right.right_most || stepSize == 0) {
        return;
    }

    if (target > right_eye_left_right.pos) {
        for (; target >= right_eye_left_right.pos; right_eye_left_right.pos += stepSize) {
            moveByMs(right_eye_left_right.comp, right_eye_left_right.pos, right_eye_left_right.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_left_right.pos; right_eye_left_right.pos -= stepSize) {
            moveByMs(right_eye_left_right.comp, right_eye_left_right.pos, right_eye_left_right.driver_num);
            delay(delay_ms);
        }
    }
}

// Function to move the eyes in a steep direction
void moveEyesSteep(uint16_t leftEyeTargetUpDown, uint16_t leftEyeTargetLeftRight, uint16_t rightEyeTargetUpDown,
                   uint16_t rightEyeTargetLeftRight, uint16_t delay_ms, uint16_t stepSize)
{
    // Move left eye up/down
    if (leftEyeTargetUpDown > left_eye_up_down.down_most || leftEyeTargetUpDown < left_eye_up_down.up_most ||
        stepSize == 0) {
        return;
    }
    if (leftEyeTargetUpDown > left_eye_up_down.pos) {
        for (; leftEyeTargetUpDown >= left_eye_up_down.pos; left_eye_up_down.pos += stepSize) {
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos, left_eye_up_down.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; leftEyeTargetUpDown <= left_eye_up_down.pos; left_eye_up_down.pos -= stepSize) {
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos, left_eye_up_down.driver_num);
            delay(delay_ms);
        }
    }

    // Move left eye left/right
    if (leftEyeTargetLeftRight > left_eye_left_right.left_most ||
        leftEyeTargetLeftRight < left_eye_left_right.right_most || stepSize == 0) {
        return;
    }
    if (leftEyeTargetLeftRight > left_eye_left_right.pos) {
        for (; leftEyeTargetLeftRight >= left_eye_left_right.pos; left_eye_left_right.pos += stepSize) {
            moveByMs(left_eye_left_right.comp, left_eye_left_right.pos, left_eye_left_right.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; leftEyeTargetLeftRight <= left_eye_left_right.pos; left_eye_left_right.pos -= stepSize) {
            moveByMs(left_eye_left_right.comp, left_eye_left_right.pos, left_eye_left_right.driver_num);
            delay(delay_ms);
        }
    }

    // Move right eye up/down
    if (rightEyeTargetUpDown < right_eye_up_down.down_most || rightEyeTargetUpDown > right_eye_up_down.up_most ||
        stepSize == 0) {
        return;
    }
    if (rightEyeTargetUpDown > right_eye_up_down.pos) {
        for (; rightEyeTargetUpDown >= right_eye_up_down.pos; right_eye_up_down.pos += stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos, right_eye_up_down.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; rightEyeTargetUpDown <= right_eye_up_down.pos; right_eye_up_down.pos -= stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos, right_eye_up_down.driver_num);
            delay(delay_ms);
        }
    }

    // Move right eye left/right
    if (rightEyeTargetLeftRight > right_eye_left_right.left_most ||
        rightEyeTargetLeftRight < right_eye_left_right.right_most || stepSize == 0) {
        return;
    }
    if (rightEyeTargetLeftRight > right_eye_left_right.pos) {
        for (; rightEyeTargetLeftRight >= right_eye_left_right.pos; right_eye_left_right.pos += stepSize) {
            moveByMs(right_eye_left_right.comp, right_eye_left_right.pos, right_eye_left_right.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; rightEyeTargetLeftRight <= right_eye_left_right.pos; right_eye_left_right.pos -= stepSize) {
            moveByMs(right_eye_left_right.comp, right_eye_left_right.pos, right_eye_left_right.driver_num);
            delay(delay_ms);
        }
    }
}

// Expression function to move both eyes steeply
void moveBothEyesSteepRandomExpression()
{
    // Generate random positions for the eyes
    uint16_t leftEyeTargetUpDown = random(left_eye_up_down.up_most, left_eye_up_down.down_most);
    uint16_t leftEyeTargetLeftRight = random(left_eye_left_right.right_most, left_eye_left_right.left_most);
    uint16_t rightEyeTargetUpDown = random(right_eye_up_down.down_most, right_eye_up_down.up_most);
    uint16_t rightEyeTargetLeftRight = random(right_eye_left_right.right_most, right_eye_left_right.left_most);

    // Move eyes to random positions in a steep direction
    moveEyesSteep(leftEyeTargetUpDown, leftEyeTargetLeftRight, rightEyeTargetUpDown, rightEyeTargetLeftRight, 3, 10);
}

// New expression function to move both eyes steeply in sync
void moveBothEyesSteepSyncExpression()
{
    // Generate random positions for up/down and left/right
    uint16_t targetUpDown = random(min(left_eye_up_down.up_most, right_eye_up_down.down_most),
                                   max(left_eye_up_down.down_most, right_eye_up_down.up_most));
    uint16_t targetLeftRight = random(min(left_eye_left_right.right_most, right_eye_left_right.right_most),
                                      max(left_eye_left_right.left_most, right_eye_left_right.left_most));

    // Move left eye to target positions
    moveEyesSteep(targetUpDown, targetLeftRight, targetUpDown, targetLeftRight, 5, 10);
}

void moveBothEyesUpDownSync(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    Serial.println("moving");
    if (stepSize == 0) {
        return;  // Prevent zero division error with step size
    }
    const uint16_t RIGHT_EYE_RANGE_SUM = right_eye_up_down.up_most + right_eye_up_down.down_most;  // 1750 + 1200
    const uint16_t LEFT_EYE_RANGE_SUM = left_eye_up_down.up_most + left_eye_up_down.down_most;

    if (target > right_eye_up_down.pos) {
        for (; target >= right_eye_up_down.pos; right_eye_up_down.pos += stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos, right_eye_up_down.driver_num); // Move right eye
            left_eye_up_down.pos = LEFT_EYE_RANGE_SUM - right_eye_up_down.pos;  // Calculate left eye position
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos, left_eye_up_down.driver_num); // Move left eye
            delay(delay_ms);
        }
    } else {
        for (; target <= right_eye_up_down.pos; right_eye_up_down.pos -= stepSize) {
            moveByMs(right_eye_up_down.comp, right_eye_up_down.pos, right_eye_up_down.driver_num); // Move right eye
            left_eye_up_down.pos = LEFT_EYE_RANGE_SUM - right_eye_up_down.pos;  // Calculate left eye position
            moveByMs(left_eye_up_down.comp, left_eye_up_down.pos, left_eye_up_down.driver_num); // Move left eye
            delay(delay_ms);
        }
    }
}

void moveBothKouteksToSmileMax(uint16_t delay_ms, uint16_t stepSize)
{
    // Calculate the step increments for moving to the smile up_most position
    int stepsLeftBottom = (leftKoutek.bottom_part_up_most - leftKoutek.bottom_comp_pos) / stepSize;
    int stepsLeftTop = (leftKoutek.top_part_up_most - leftKoutek.top_comp_pos) / stepSize;
    int stepsRightBottom = (rightKoutek.bottom_part_smile_most - rightKoutek.bottom_comp_pos) / stepSize;
    int stepsRightTop = (rightKoutek.top_part_up_most - rightKoutek.top_comp_pos) / stepSize;

    // Handle movement for each component
    for (int step = 0; step < abs(stepsLeftBottom); step++) {
        leftKoutek.bottom_comp_pos += (stepsLeftBottom > 0 ? stepSize : -stepSize);
        leftKoutek.top_comp_pos += (stepsLeftTop > 0 ? stepSize : -stepSize);
        rightKoutek.bottom_comp_pos += (stepsRightBottom > 0 ? stepSize : -stepSize);
        rightKoutek.top_comp_pos += (stepsRightTop > 0 ? stepSize : -stepSize);

        // Apply the movement
        moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_comp_pos, leftKoutek.driver_num);
        moveByMs(leftKoutek.top_comp, leftKoutek.top_comp_pos, leftKoutek.driver_num);
        moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_comp_pos, rightKoutek.driver_num);
        moveByMs(rightKoutek.top_comp, rightKoutek.top_comp_pos, rightKoutek.driver_num);

        // Delay between steps
        delay(delay_ms);
    }

    // Ensure all servos are set to the exact up_most smile position at the end
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_part_up_most, leftKoutek.driver_num);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_part_up_most, leftKoutek.driver_num);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_part_smile_most, rightKoutek.driver_num);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_part_up_most, rightKoutek.driver_num);
}

void moveBothKouteksToFrownMax(uint16_t delay_ms, uint16_t stepSize)
{
    // Calculate the number of steps each koutek part needs to reach its smile up_most
    int stepsLeftBottom = abs(leftKoutek.bottom_part_up_most - leftKoutek.bottom_comp_pos) / stepSize;
    int stepsLeftTop = abs(leftKoutek.top_part_up_most - leftKoutek.top_comp_pos) / stepSize;
    int stepsRightBottom = abs(rightKoutek.bottom_part_smile_most - rightKoutek.bottom_comp_pos) / stepSize;
    int stepsRightTop = abs(rightKoutek.top_part_up_most - rightKoutek.top_comp_pos) / stepSize;

    // Find the maximum steps needed to synchronize the movements
    int maxSteps = max(max(stepsLeftBottom, stepsLeftTop), max(stepsRightBottom, stepsRightTop));

    // Calculate the actual step sizes for each movement to synchronize the end point
    float stepLeftBottom = (float) (leftKoutek.bottom_part_up_most - leftKoutek.bottom_comp_pos) / maxSteps;
    float stepLeftTop = (float) (leftKoutek.top_part_up_most - leftKoutek.top_comp_pos) / maxSteps;
    float stepRightBottom = (float) (rightKoutek.bottom_part_smile_most - rightKoutek.bottom_comp_pos) / maxSteps;
    float stepRightTop = (float) (rightKoutek.top_part_up_most - rightKoutek.top_comp_pos) / maxSteps;

    for (int i = 0; i < maxSteps; i++) {
        // Incrementally move each part towards its target
        leftKoutek.bottom_comp_pos += stepLeftBottom;
        leftKoutek.top_comp_pos += stepLeftTop;
        rightKoutek.bottom_comp_pos += stepRightBottom;
        rightKoutek.top_comp_pos += stepRightTop;

        // Apply the movement
        moveByMs(leftKoutek.bottom_comp, (uint16_t) (leftKoutek.bottom_comp_pos), leftKoutek.driver_num);
        moveByMs(leftKoutek.top_comp, (uint16_t) (leftKoutek.top_comp_pos), leftKoutek.driver_num);
        moveByMs(rightKoutek.bottom_comp, (uint16_t) (rightKoutek.bottom_comp_pos), rightKoutek.driver_num);
        moveByMs(rightKoutek.top_comp, (uint16_t) (rightKoutek.top_comp_pos), rightKoutek.driver_num);

        // Delay between steps
        delay(delay_ms);
    }

    // Ensure all servos are set to the exact up_most smile position at the end
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_part_up_most, leftKoutek.driver_num);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_part_up_most, leftKoutek.driver_num);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_part_smile_most, rightKoutek.driver_num);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_part_up_most, rightKoutek.driver_num);
}
*/

/*
void (* expressions[])() = {
        moveBothEyesSteepRandomExpression,
        moveBothEyesSteepSyncExpression
};
*/

void setup()
{
    Serial.begin(115200);

    setupDrivers();

    right_eye_left_right.move_center();
    right_eye_up_down.move_center();
    left_eye_up_down.move_center();
    left_eye_left_right.move_center();

    /*driver0.begin();
    driver0.setPWMFreq(60);

    driver1.begin();
    driver1.setPWMFreq(60);*/

    delay(500);

    /*moveLeftEyeUpDown(left_eye_up_down.center, 5, 10);
    moveRightEyeUpDown(right_eye_up_down.center, 5, 10);
    delay(random(4000, 8000));
    moveLeftEyeUpDown(left_eye_up_down.up_most, 5, 10);
    moveRightEyeUpDown(right_eye_up_down.up_most, 5, 10);
    delay(random(4000, 8000));
    moveLeftEyeUpDown(left_eye_up_down.down_most, 5, 10);
    moveRightEyeUpDown(right_eye_up_down.down_most, 5, 10);
    delay(10000);*/


    /*moveLeftEyeLeftRight(left_eye_left_right.center, 5, 10);*/
    /*moveRightEyeLeftRight(right_eye_left_right.center, 5, 10);
    delay(5000);
    *//*moveLeftEyeLeftRight(left_eye_left_right.left_most, 5, 10);*//*
    moveRightEyeLeftRight(right_eye_left_right.left_most, 5, 10);
    delay(5000);
    *//*moveLeftEyeLeftRight(left_eye_left_right.right_most, 5, 10);*//*
    moveRightEyeLeftRight(right_eye_left_right.right_most, 5, 10);
    delay(5000);*/
    /*
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_comp_pos, leftKoutek.driver_num);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_comp_pos, leftKoutek.driver_num);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_comp_pos, rightKoutek.driver_num);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_comp_pos, rightKoutek.driver_num);*/


    /*for (; right_eye_up_down.pos <= right_eye_up_down.up_most ; right_eye_up_down.pos++) {
        moveByMs(right_eye_up_down.comp, right_eye_up_down.pos,right_eye_up_down.driver_num);
    }

    for (; right_eye_up_down.pos <= right_eye_up_down.up_most ; right_eye_up_down.pos++) {
        moveByMs(right_eye_up_down.comp, right_eye_up_down.pos,right_eye_up_down.driver_num);
    }

    delay(500);

    for (; right_eye_left_right.pos <= right_eye_left_right.right_most; right_eye_left_right.pos++) {
        moveByMs(right_eye_left_right.comp, right_eye_left_right.pos,right_eye_left_right.driver_num);
    }
    delay(500);

    for (; right_eye_left_right.pos >= right_eye_left_right.left_most; right_eye_left_right.pos--) {
        moveByMs(right_eye_left_right.comp, right_eye_left_right.pos,right_eye_left_right.driver_num);
    }*/

    int delay_ms = 100;
    right_eye_up_down.move_center();
    delay(delay_ms);
    right_eye_left_right.move_center();
    delay(delay_ms);
    left_eye_up_down.move_center();
    delay(delay_ms);
    left_eye_left_right.move_center();
    delay(delay_ms);
}

void loop()
{
    // Select a random expression from the array
    /*int randomIndex = random(0, sizeof(expressions) / sizeof(expressions[0]));*/
    /*expressions[randomIndex]();*/
    // Wait for a random amount of time between 4 to 8 seconds before executing the next expression
    delay(random(4000, 8000));

    /* int delay_ms = 500;
     right_eye_up_down.move_center();
     delay(delay_ms);
     right_eye_left_right.move_center();
     delay(delay_ms);
     left_eye_up_down.move_center();
     delay(delay_ms);
     left_eye_left_right.move_center();
     delay(delay_ms);

     left_eye_up_down.move_up_most();
     delay(delay_ms);
     right_eye_up_down.move_up_most();
     delay(delay_ms);
     left_eye_up_down.move_down_most();
     delay(delay_ms);
     right_eye_up_down.move_down_most();
     delay(delay_ms);*/

}
