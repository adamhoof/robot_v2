#include "face/mouth/teeth/top/top_tooth_center.h"

void TopToothCenter::move_up_by(uint16_t moveBy)
{
    if (pos + moveBy > up_most) {
        move_to(part, up_most, driver_num);
        pos = up_most;
    } else {
        move_to(part, pos + moveBy, driver_num);
        pos += moveBy;
    }
}

void TopToothCenter::move_center()
{
    Serial.print("Starting at: ");
    Serial.println(pos);

    move_to(part, center, driver_num);
    pos = center;

    Serial.print("Moved to: ");
    Serial.println(pos);
}

void TopToothCenter::move_up_most()
{
    move_to(part, up_most, driver_num);
    pos = up_most;
}

void TopToothCenter::move_down_by(uint16_t moveBy)
{
    if (pos - moveBy < center) {
        move_to(part, center, driver_num);
        pos = center;
    } else {
        move_to(part, pos - moveBy, driver_num);
        pos -= moveBy;
    }
}

void TopToothCenter::move_down_most()
{
    move_center();
}
