#include "face/eyes/left/left_eye_up_down.h"

void LeftEyeUpDown::move_center()
{
    moveByMs(comp, center, driver_num);
    pos = center;
}

void LeftEyeUpDown::move_up_most()
{
    moveByMs(comp, up_most, driver_num);
    pos = up_most;
}

void LeftEyeUpDown::move_down_most()
{
    moveByMs(comp, down_most, driver_num);
    pos = down_most;
}

void LeftEyeUpDown::move_up_by(uint16_t moveBy)
{
    if (pos + moveBy > up_most) {
        moveByMs(comp, up_most, driver_num);
        pos = up_most;
    } else {
        moveByMs(comp, pos + moveBy, driver_num);
        pos += moveBy;
    }
}

void LeftEyeUpDown::move_down_by(uint16_t moveBy)
{
    if (pos - moveBy < down_most) {
        moveByMs(comp, down_most, driver_num);
        pos = down_most;
    } else {
        moveByMs(comp, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}
