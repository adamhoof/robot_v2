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

void (* expressions[])() = {
};

void setup()
{
    Serial.begin(115200);

    setupDrivers();

    int move_delay = 1000;
    delay(500);

    /*leftKoutekTop.move_center();*/
    /*leftKoutekBottom.move_center();*/

    rightKoutekTop.move_center();
    rightKoutekBottom.move_center();


    delay(move_delay);
    /*leftKoutekTop.move_up_most();*/
    /*leftKoutekBottom.move_up_most();*/

    rightKoutekTop.move_up_most();
    rightKoutekBottom.move_up_most();


    delay(move_delay);
    /*leftKoutekTop.move_center();*/
    /*leftKoutekBottom.move_center();*/

    rightKoutekTop.move_center();
    rightKoutekBottom.move_center();


    delay(move_delay);
    /*leftKoutekTop.move_down_most();*/
    /*leftKoutekBottom.move_down_most();*/

    rightKoutekTop.move_down_most();
    rightKoutekBottom.move_down_most();


    delay(move_delay);
    /*leftKoutekTop.move_center();*/
    /*leftKoutekBottom.move_center();*/

    rightKoutekTop.move_center();
    rightKoutekBottom.move_center();
}

void loop()
{

    /*int randomIndex = random(0, sizeof(expressions) / sizeof(expressions[0]));*/
    /*expressions[randomIndex]();*/
    delay(random(4000, 8000));
}
