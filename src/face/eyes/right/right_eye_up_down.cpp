#include "face/eyes/right/right_eye_up_down.h"

void RightEyeUpDown::move_center() {
    move_to(comp, center, driver_num);
    pos = center;
}

void RightEyeUpDown::move_up_most() {
    move_to(comp, up_most, driver_num);
    pos = up_most;
}

void RightEyeUpDown::move_down_most() {
    move_to(comp, down_most, driver_num);
    pos = down_most;
}

void RightEyeUpDown::move_up_by(uint16_t moveBy) {
    if (pos + moveBy > up_most) {
        move_to(comp, up_most, driver_num);
        pos = up_most;
    } else {
        move_to(comp, pos + moveBy, driver_num);
        pos += moveBy;
    }
}

void RightEyeUpDown::move_down_by(uint16_t moveBy) {
    if (pos < moveBy + down_most) {
        move_to(comp, down_most, driver_num);
        pos = down_most;
    } else {
        move_to(comp, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}
