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
    delay(2);
    leftKoutekBottom.move_center();
    delay(2);
    rightKoutekTop.move_center();
    delay(2);
    rightKoutekBottom.move_center();
    delay(2);
    leftEyeUpDown.move_center();
    delay(2);
    leftEyeLeftRight.move_center();
    delay(2);
    rightEyeUpDown.move_center();
    delay(2);
    rightEyeLeftRight.move_center();
    delay(2);
    leftLidTop.move_center();
    delay(2);
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
    delay(2);
    leftKoutekBottom.move_down_most();
    delay(2);
    rightKoutekTop.move_up_most();
    delay(2);
    rightKoutekBottom.move_down_most();
    delay(2);
    leftEyeUpDown.move_center();
    delay(2);
    leftEyeLeftRight.move_center();
    delay(2);
    rightEyeUpDown.move_center();
    delay(2);
    rightEyeLeftRight.move_center();
}

void angry() {
    leftKoutekTop.move_down_most();
    delay(2);
    leftKoutekBottom.move_down_most();
    delay(2);
    rightKoutekTop.move_down_most();
    delay(2);
    rightKoutekBottom.move_down_most();
    delay(2);
    leftEyeUpDown.move_down_most();
    delay(2);
    leftEyeLeftRight.move_left_most();
    delay(2);
    rightEyeUpDown.move_down_most();
    delay(2);
    rightEyeLeftRight.move_right_most();
}

void look_left() {
    leftEyeLeftRight.move_left_most();
    delay(2);
    rightEyeLeftRight.move_left_most();
}

void look_right() {
    leftEyeLeftRight.move_right_most();
    delay(2);
    rightEyeLeftRight.move_right_most();
}

void look_up() {
    leftEyeUpDown.move_up_most();
    delay(2);
    rightEyeUpDown.move_up_most();
}

void look_down() {
    leftEyeUpDown.move_down_most();
    delay(2);
    rightEyeUpDown.move_down_most();
}

void surprise() {
    leftKoutekTop.move_down_most();
    delay(2);
    leftKoutekBottom.move_down_most();
    delay(2);
    rightKoutekTop.move_down_most();
    delay(2);
    rightKoutekBottom.move_down_most();
    delay(2);
    leftEyeUpDown.move_up_most();
    delay(2);
    rightEyeUpDown.move_up_most();
    delay(2);
    leftLidTop.move_up_most();
    delay(2);
    rightLidTop.move_up_most();
}

void blink() {
    leftLidTop.move_down_most();
    delay(2);
    rightLidTop.move_down_most();
    delay(2);
    leftLidTop.move_up_most();
    delay(2);
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
