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

LeftEyeUpDown leftEyeUpDown;
RightEyeUpDown rightEyeUpDown;
LeftEyeLeftRight leftEyeLeftRight;
RightEyeLeftRight rightEyeLeftRight;
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
    if (target > leftEyeUpDown.down_most || target < leftEyeUpDown.up_most || stepSize == 0) {
        return;
    }

    if (target > leftEyeUpDown.pos) {
        for (; target >= leftEyeUpDown.pos; leftEyeUpDown.pos += stepSize) {
            moveByMs(leftEyeUpDown.comp, leftEyeUpDown.pos, leftEyeUpDown.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= leftEyeUpDown.pos; leftEyeUpDown.pos -= stepSize) {
            moveByMs(leftEyeUpDown.comp, leftEyeUpDown.pos, leftEyeUpDown.driver_num);
            delay(delay_ms);
        }
    }
}

void moveRightEyeUpDown(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target < rightEyeUpDown.down_most || target > rightEyeUpDown.up_most || stepSize == 0) {
        return;
    }

    if (target > rightEyeUpDown.pos) {
        for (; target >= rightEyeUpDown.pos; rightEyeUpDown.pos += stepSize) {
            moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos, rightEyeUpDown.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= rightEyeUpDown.pos; rightEyeUpDown.pos -= stepSize) {
            moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos, rightEyeUpDown.driver_num);
            delay(delay_ms);
        }
    }
}

void moveLeftEyeLeftRight(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target > leftEyeLeftRight.left_most || target < leftEyeLeftRight.right_most || stepSize == 0) {
        return;
    }

    if (target > leftEyeLeftRight.pos) {
        for (; target >= leftEyeLeftRight.pos; leftEyeLeftRight.pos += stepSize) {
            moveByMs(leftEyeLeftRight.comp, leftEyeLeftRight.pos, leftEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= leftEyeLeftRight.pos; leftEyeLeftRight.pos -= stepSize) {
            moveByMs(leftEyeLeftRight.comp, leftEyeLeftRight.pos, leftEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    }
}

void moveRightEyeLeftRight(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    if (target > rightEyeLeftRight.left_most || target < rightEyeLeftRight.right_most || stepSize == 0) {
        return;
    }

    if (target > rightEyeLeftRight.pos) {
        for (; target >= rightEyeLeftRight.pos; rightEyeLeftRight.pos += stepSize) {
            moveByMs(rightEyeLeftRight.comp, rightEyeLeftRight.pos, rightEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; target <= rightEyeLeftRight.pos; rightEyeLeftRight.pos -= stepSize) {
            moveByMs(rightEyeLeftRight.comp, rightEyeLeftRight.pos, rightEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    }
}

// Function to move the eyes in a steep direction
void moveEyesSteep(uint16_t leftEyeTargetUpDown, uint16_t leftEyeTargetLeftRight, uint16_t rightEyeTargetUpDown,
                   uint16_t rightEyeTargetLeftRight, uint16_t delay_ms, uint16_t stepSize)
{
    // Move left eye up/down
    if (leftEyeTargetUpDown > leftEyeUpDown.down_most || leftEyeTargetUpDown < leftEyeUpDown.up_most ||
        stepSize == 0) {
        return;
    }
    if (leftEyeTargetUpDown > leftEyeUpDown.pos) {
        for (; leftEyeTargetUpDown >= leftEyeUpDown.pos; leftEyeUpDown.pos += stepSize) {
            moveByMs(leftEyeUpDown.comp, leftEyeUpDown.pos, leftEyeUpDown.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; leftEyeTargetUpDown <= leftEyeUpDown.pos; leftEyeUpDown.pos -= stepSize) {
            moveByMs(leftEyeUpDown.comp, leftEyeUpDown.pos, leftEyeUpDown.driver_num);
            delay(delay_ms);
        }
    }

    // Move left eye left/right
    if (leftEyeTargetLeftRight > leftEyeLeftRight.left_most ||
        leftEyeTargetLeftRight < leftEyeLeftRight.right_most || stepSize == 0) {
        return;
    }
    if (leftEyeTargetLeftRight > leftEyeLeftRight.pos) {
        for (; leftEyeTargetLeftRight >= leftEyeLeftRight.pos; leftEyeLeftRight.pos += stepSize) {
            moveByMs(leftEyeLeftRight.comp, leftEyeLeftRight.pos, leftEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; leftEyeTargetLeftRight <= leftEyeLeftRight.pos; leftEyeLeftRight.pos -= stepSize) {
            moveByMs(leftEyeLeftRight.comp, leftEyeLeftRight.pos, leftEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    }

    // Move right eye up/down
    if (rightEyeTargetUpDown < rightEyeUpDown.down_most || rightEyeTargetUpDown > rightEyeUpDown.up_most ||
        stepSize == 0) {
        return;
    }
    if (rightEyeTargetUpDown > rightEyeUpDown.pos) {
        for (; rightEyeTargetUpDown >= rightEyeUpDown.pos; rightEyeUpDown.pos += stepSize) {
            moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos, rightEyeUpDown.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; rightEyeTargetUpDown <= rightEyeUpDown.pos; rightEyeUpDown.pos -= stepSize) {
            moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos, rightEyeUpDown.driver_num);
            delay(delay_ms);
        }
    }

    // Move right eye left/right
    if (rightEyeTargetLeftRight > rightEyeLeftRight.left_most ||
        rightEyeTargetLeftRight < rightEyeLeftRight.right_most || stepSize == 0) {
        return;
    }
    if (rightEyeTargetLeftRight > rightEyeLeftRight.pos) {
        for (; rightEyeTargetLeftRight >= rightEyeLeftRight.pos; rightEyeLeftRight.pos += stepSize) {
            moveByMs(rightEyeLeftRight.comp, rightEyeLeftRight.pos, rightEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    } else {
        for (; rightEyeTargetLeftRight <= rightEyeLeftRight.pos; rightEyeLeftRight.pos -= stepSize) {
            moveByMs(rightEyeLeftRight.comp, rightEyeLeftRight.pos, rightEyeLeftRight.driver_num);
            delay(delay_ms);
        }
    }
}

// Expression function to move both eyes steeply
void moveBothEyesSteepRandomExpression()
{
    // Generate random positions for the eyes
    uint16_t leftEyeTargetUpDown = random(leftEyeUpDown.up_most, leftEyeUpDown.down_most);
    uint16_t leftEyeTargetLeftRight = random(leftEyeLeftRight.right_most, leftEyeLeftRight.left_most);
    uint16_t rightEyeTargetUpDown = random(rightEyeUpDown.down_most, rightEyeUpDown.up_most);
    uint16_t rightEyeTargetLeftRight = random(rightEyeLeftRight.right_most, rightEyeLeftRight.left_most);

    // Move eyes to random positions in a steep direction
    moveEyesSteep(leftEyeTargetUpDown, leftEyeTargetLeftRight, rightEyeTargetUpDown, rightEyeTargetLeftRight, 3, 10);
}

// New expression function to move both eyes steeply in sync
void moveBothEyesSteepSyncExpression()
{
    // Generate random positions for up/down and left/right
    uint16_t targetUpDown = random(min(leftEyeUpDown.up_most, rightEyeUpDown.down_most),
                                   max(leftEyeUpDown.down_most, rightEyeUpDown.up_most));
    uint16_t targetLeftRight = random(min(leftEyeLeftRight.right_most, rightEyeLeftRight.right_most),
                                      max(leftEyeLeftRight.left_most, rightEyeLeftRight.left_most));

    // Move left eye to target positions
    moveEyesSteep(targetUpDown, targetLeftRight, targetUpDown, targetLeftRight, 5, 10);
}

void moveBothEyesUpDownSync(uint16_t target, uint16_t delay_ms, uint16_t stepSize)
{
    Serial.println("moving");
    if (stepSize == 0) {
        return;  // Prevent zero division error with step size
    }
    const uint16_t RIGHT_EYE_RANGE_SUM = rightEyeUpDown.up_most + rightEyeUpDown.down_most;  // 1750 + 1200
    const uint16_t LEFT_EYE_RANGE_SUM = leftEyeUpDown.up_most + leftEyeUpDown.down_most;

    if (target > rightEyeUpDown.pos) {
        for (; target >= rightEyeUpDown.pos; rightEyeUpDown.pos += stepSize) {
            moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos, rightEyeUpDown.driver_num); // Move right eye
            leftEyeUpDown.pos = LEFT_EYE_RANGE_SUM - rightEyeUpDown.pos;  // Calculate left eye position
            moveByMs(leftEyeUpDown.comp, leftEyeUpDown.pos, leftEyeUpDown.driver_num); // Move left eye
            delay(delay_ms);
        }
    } else {
        for (; target <= rightEyeUpDown.pos; rightEyeUpDown.pos -= stepSize) {
            moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos, rightEyeUpDown.driver_num); // Move right eye
            leftEyeUpDown.pos = LEFT_EYE_RANGE_SUM - rightEyeUpDown.pos;  // Calculate left eye position
            moveByMs(leftEyeUpDown.comp, leftEyeUpDown.pos, leftEyeUpDown.driver_num); // Move left eye
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
    delay(2000);

    rightEyeLeftRight.move_center();
    leftEyeLeftRight.move_center();
    rightEyeUpDown.move_center();
    leftEyeUpDown.move_center();

    delay(2000);
    rightEyeLeftRight.move_right_most();
    leftEyeLeftRight.move_right_most();
    rightEyeUpDown.move_up_most();
    leftEyeUpDown.move_up_most();

    delay(2000);
    rightEyeLeftRight.move_center();
    leftEyeLeftRight.move_center();
    rightEyeUpDown.move_center();
    leftEyeUpDown.move_center();

    delay(2000);
    rightEyeLeftRight.move_left_most();
    leftEyeLeftRight.move_left_most();
    rightEyeUpDown.move_down_most();
    leftEyeUpDown.move_down_most();

    /*moveLeftEyeUpDown(leftEyeUpDown.center, 5, 10);
    moveRightEyeUpDown(rightEyeUpDown.center, 5, 10);
    delay(random(4000, 8000));
    moveLeftEyeUpDown(leftEyeUpDown.up_most, 5, 10);
    moveRightEyeUpDown(rightEyeUpDown.up_most, 5, 10);
    delay(random(4000, 8000));
    moveLeftEyeUpDown(leftEyeUpDown.down_most, 5, 10);
    moveRightEyeUpDown(rightEyeUpDown.down_most, 5, 10);
    delay(10000);*/


    /*moveLeftEyeLeftRight(leftEyeLeftRight.center, 5, 10);*/
    /*moveRightEyeLeftRight(rightEyeLeftRight.center, 5, 10);
    delay(5000);
    *//*moveLeftEyeLeftRight(leftEyeLeftRight.left_most, 5, 10);*//*
    moveRightEyeLeftRight(rightEyeLeftRight.left_most, 5, 10);
    delay(5000);
    *//*moveLeftEyeLeftRight(leftEyeLeftRight.right_most, 5, 10);*//*
    moveRightEyeLeftRight(rightEyeLeftRight.right_most, 5, 10);
    delay(5000);*/
    /*
    moveByMs(leftKoutek.bottom_comp, leftKoutek.bottom_comp_pos, leftKoutek.driver_num);
    moveByMs(leftKoutek.top_comp, leftKoutek.top_comp_pos, leftKoutek.driver_num);
    moveByMs(rightKoutek.bottom_comp, rightKoutek.bottom_comp_pos, rightKoutek.driver_num);
    moveByMs(rightKoutek.top_comp, rightKoutek.top_comp_pos, rightKoutek.driver_num);*/


    /*for (; rightEyeUpDown.pos <= rightEyeUpDown.up_most ; rightEyeUpDown.pos++) {
        moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos,rightEyeUpDown.driver_num);
    }

    for (; rightEyeUpDown.pos <= rightEyeUpDown.up_most ; rightEyeUpDown.pos++) {
        moveByMs(rightEyeUpDown.comp, rightEyeUpDown.pos,rightEyeUpDown.driver_num);
    }

    delay(500);

    for (; rightEyeLeftRight.pos <= rightEyeLeftRight.right_most; rightEyeLeftRight.pos++) {
        moveByMs(rightEyeLeftRight.comp, rightEyeLeftRight.pos,rightEyeLeftRight.driver_num);
    }
    delay(500);

    for (; rightEyeLeftRight.pos >= rightEyeLeftRight.left_most; rightEyeLeftRight.pos--) {
        moveByMs(rightEyeLeftRight.comp, rightEyeLeftRight.pos,rightEyeLeftRight.driver_num);
    }*/
}

void loop()
{
    // Select a random expression from the array
    /*int randomIndex = random(0, sizeof(expressions) / sizeof(expressions[0]));*/
    /*expressions[randomIndex]();*/
    // Wait for a random amount of time between 4 to 8 seconds before executing the next expression
    delay(random(4000, 8000));

    /* int delay_ms = 500;
     rightEyeUpDown.move_center();
     delay(delay_ms);
     rightEyeLeftRight.move_center();
     delay(delay_ms);
     leftEyeUpDown.move_center();
     delay(delay_ms);
     leftEyeLeftRight.move_center();
     delay(delay_ms);

     leftEyeUpDown.move_up_most();
     delay(delay_ms);
     rightEyeUpDown.move_up_most();
     delay(delay_ms);
     leftEyeUpDown.move_down_most();
     delay(delay_ms);
     rightEyeUpDown.move_down_most();
     delay(delay_ms);*/

}
