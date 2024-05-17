#include "face/mouth/koutky/left/left_koutek_top.h"

void LeftKoutekTop::move_center()
{
    move_to(port, center, driver_num);
    pos = center;
}

void LeftKoutekTop::move_up_most()
{
    move_to(port, up_most, driver_num);
    pos = up_most;
}

void LeftKoutekTop::move_down_most()
{
    move_to(port,down_most,driver_num);
    pos = down_most;
}

void LeftKoutekTop::move_up_by(uint16_t moveBy)
{
    if (pos + moveBy > up_most) {
        move_up_most();
    } else {
        move_to(port, pos + moveBy, driver_num);
        pos += moveBy;
    }
}

void LeftKoutekTop::move_down_by(uint16_t moveBy)
{
    if (pos - moveBy < down_most) {
        move_down_most();
    } else {
        move_to(port, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}
