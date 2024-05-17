#include "face/eyes/right/right_eye_left_right.h"

void RightEyeLeftRight::move_center()
{
    moveByMs(comp, center, driver_num);
    pos = center;
}

void RightEyeLeftRight::move_left_most()
{
    moveByMs(comp, left_most, driver_num);
    pos = left_most;
}

void RightEyeLeftRight::move_right_most()
{
    moveByMs(comp, right_most, driver_num);
    pos = right_most;
}

void RightEyeLeftRight::move_right_by(uint16_t moveBy)
{
    if (pos + moveBy > right_most) {
        moveByMs(comp, right_most, driver_num);
        pos = right_most;
    } else {
        moveByMs(comp, pos + moveBy, driver_num);
        pos += moveBy;
    }
}

void RightEyeLeftRight::move_left_by(uint16_t moveBy)
{
    if (pos - moveBy < left_most) {
        moveByMs(comp, left_most, driver_num);
        pos = left_most;
    } else {
        moveByMs(comp, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}
