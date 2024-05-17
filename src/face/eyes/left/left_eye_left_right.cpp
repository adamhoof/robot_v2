#include "face/eyes/left/left_eye_left_right.h"

void LeftEyeLeftRight::move_center()
{
    move_to(comp, center, driver_num);
    pos = center;
}

void LeftEyeLeftRight::move_left_most()
{
    move_to(comp, left_most, driver_num);
    pos = left_most;
}

void LeftEyeLeftRight::move_right_most()
{
    move_to(comp, right_most, driver_num);
    pos = right_most;
}

void LeftEyeLeftRight::move_right_by(uint16_t moveBy)
{
    if (pos - moveBy < right_most) {
        move_to(comp, right_most, driver_num);
        pos = right_most;
    } else {
        move_to(comp, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}

void LeftEyeLeftRight::move_left_by(uint16_t moveBy)
{
    if (pos + moveBy > left_most) {
        move_to(comp, left_most, driver_num);
        pos = left_most;
    } else {
        move_to(comp, pos + moveBy, driver_num);
        pos += moveBy;
    }
}
