//
// Created by adamhoof on 17.5.24.
//

#include "face/lids/right/right_lid_top.h"

void RightLidTop::move_center()
{
    move_to(part,center,driver_num);
    pos = center;
}

void RightLidTop::move_up_most()
{
    move_to(part,up_most,driver_num);
    pos = up_most;
}

void RightLidTop::move_down_most()
{
    move_to(part,down_most,driver_num);
    pos = down_most;
}

void RightLidTop::move_up_by(uint16_t moveBy)
{
    if (pos - moveBy < up_most) {
        move_up_most();
    } else {
        move_to(part, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}

void RightLidTop::move_down_by(uint16_t moveBy)
{
    if (pos + moveBy > up_most) {
        move_down_most();
    } else {
        move_to(part, pos + moveBy, driver_num);
        pos += moveBy;
    }
}
