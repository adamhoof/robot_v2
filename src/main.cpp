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
#include "face/mouth/koutky/right/right_koutek_top.h"
#include "face/mouth/koutky/left/left_koutek_bottom.h"
#include "face/lids/right/right_lid_up.h"
#include "face/lids/right/right_lid_down.h"
#include "face/mouth/koutky/left/left_koutek_top.h"
#include "face/mouth/koutky/right/right_koutek_bottom.h"

LeftEyeUpDown leftEyeUpDown;
RightEyeUpDown rightEyeUpDown;
LeftEyeLeftRight leftEyeLeftRight;
RightEyeLeftRight rightEyeLeftRight;
LeftKoutekBottom leftKoutekBottom;
LeftKoutekTop leftKoutekTop;
RightKoutekTop rightKoutekTop;
RightKoutekBottom rightKoutekBottom;
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

void centerAll()
{
    leftKoutekTop.move_center();
    leftKoutekBottom.move_center();

    rightKoutekTop.move_center();
    rightKoutekBottom.move_center();

    leftEyeUpDown.move_center();
    leftEyeLeftRight.move_center();

    rightEyeUpDown.move_center();
    rightEyeLeftRight.move_center();
}

void fuckFace()
{
    leftKoutekTop.move_up_most();
    leftKoutekBottom.move_up_most();

    rightKoutekTop.move_up_most();
    rightKoutekBottom.move_up_most();

    rightEyeUpDown.move_up_most();
    rightEyeLeftRight.move_left_most();

    leftEyeUpDown.move_up_most();
    leftEyeLeftRight.move_right_most();
}

void (* expressions[])() = {
        fuckFace,
        centerAll
};

void setup()
{
    Serial.begin(115200);

    setupDrivers();

    delay(100);

    centerAll();
}

void loop()
{

    int randomIndex = random(0, sizeof(expressions) / sizeof(expressions[0]));
    expressions[randomIndex]();
    delay(random(1500, 4000));
}
