#include <Arduino.h>
#include "driver.h"
#include "face/eyes/left/left_eye_left_right.h"
#include "face/eyes/left/left_eye_up_down.h"
#include "face/eyes/right/right_eye_left_right.h"
#include "face/eyes/right/right_eye_up_down.h"
#include "face/mouth/chin/chin.h"
#include "face/mouth/teeth/top/top_tooth_left.h"
#include "face/mouth/teeth/bottom/bottom_tooth_right.h"
#include "face/mouth/teeth/bottom/bottom_tooth_center.h"
#include "face/mouth/teeth/bottom/bottom_tooth_left.h"
#include "face/mouth/teeth/top/top_tooth_right.h"
#include "face/mouth/teeth/top/top_tooth_center.h"
#include "face/mouth/koutky/right/right_koutek_top.h"
#include "face/mouth/koutky/left/left_koutek_bottom.h"
#include "face/mouth/koutky/left/left_koutek_top.h"
#include "face/mouth/koutky/right/right_koutek_bottom.h"
#include "face/lids/left/left_lid_bottom.h"
#include "face/lids/left/left_lid_top.h"
#include "face/lids/right/right_lid_top.h"
#include "face/lids/right/right_lid_bottom.h"

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
LeftLidTop leftLidTop;
LeftLidBottom leftLidBottom;
RightLidTop rightLidTop;
RightLidBottom rightLidBottom;
Chin chin;

void centerAll() {
    leftKoutekTop.move_center();
    leftKoutekBottom.move_center();
    rightKoutekTop.move_center();
    rightKoutekBottom.move_center();
    leftEyeUpDown.move_center();
    leftEyeLeftRight.move_center();
    rightEyeUpDown.move_center();
    rightEyeLeftRight.move_center();
    leftLidTop.move_center();
    rightLidTop.move_center();
}

void fuckFace() {
    leftKoutekTop.move_up_most();
    leftKoutekBottom.move_up_most();
    rightKoutekTop.move_up_most();
    rightKoutekBottom.move_up_most();
    rightEyeUpDown.move_up_most();
    rightEyeLeftRight.move_left_most();
    leftEyeUpDown.move_up_most();
    leftEyeLeftRight.move_right_most();
}

void smile() {
    leftKoutekTop.move_up_most();
    leftKoutekBottom.move_down_most();
    rightKoutekTop.move_up_most();
    rightKoutekBottom.move_down_most();
    leftEyeUpDown.move_center();
    leftEyeLeftRight.move_center();
    rightEyeUpDown.move_center();
    rightEyeLeftRight.move_center();
}

void angry() {
    leftKoutekTop.move_down_most();
    leftKoutekBottom.move_down_most();
    rightKoutekTop.move_down_most();
    rightKoutekBottom.move_down_most();
    leftEyeUpDown.move_down_most();
    leftEyeLeftRight.move_left_most();
    rightEyeUpDown.move_down_most();
    rightEyeLeftRight.move_right_most();
}

void look_left() {
    leftEyeLeftRight.move_left_most();
    rightEyeLeftRight.move_left_most();
}

void look_right() {
    leftEyeLeftRight.move_right_most();
    rightEyeLeftRight.move_right_most();
}

void look_up() {
    leftEyeUpDown.move_up_most();
    rightEyeUpDown.move_up_most();
}

void look_down() {
    leftEyeUpDown.move_down_most();
    rightEyeUpDown.move_down_most();
}

void surprise() {
    leftKoutekTop.move_down_most();
    leftKoutekBottom.move_down_most();
    rightKoutekTop.move_down_most();
    rightKoutekBottom.move_down_most();
    leftEyeUpDown.move_up_most();
    rightEyeUpDown.move_up_most();
    leftLidTop.move_up_most();
    rightLidTop.move_up_most();
}

void blink() {
    leftLidTop.move_down_most();
    rightLidTop.move_down_most();
    delay(100);
    leftLidTop.move_up_most();
    rightLidTop.move_up_most();
}

void (*expressions[])() = {
        centerAll,
        fuckFace,
        smile,
        angry,
        look_left,
        look_right,
        look_up,
        look_down,
        surprise,
        blink,
        //suspicious

};

void setup() {
    Serial.begin(115200);
    setupDrivers();
    delay(100);
    centerAll();
    delay(100);

    blink();
    delay(50000);
}

void loop() {
    int randomIndex = random(0, sizeof(expressions) / sizeof(expressions[0]));
    expressions[randomIndex]();
    delay(random(1500, 4000));
}
