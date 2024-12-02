#include "device.hpp"
#include "esp32-hal-gpio.h"
#include <vector2.hpp>

Vector2 Vector2::GlobalToDisplay() const {
    // (0, 0) -> row 3 column 15
    return *this * -1 + Vector2(15, 3) ;
}

void Vector2::Draw() const {
    Vector2 displayPos = this->GlobalToDisplay();
    native_display.setPoint(displayPos.y, displayPos.x, HIGH);
}

void Vector2::Clear() const {
    Vector2 displayPos = this->GlobalToDisplay();
    native_display.setPoint(displayPos.y, displayPos.x, LOW);
}
