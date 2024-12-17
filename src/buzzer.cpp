#include "buzzer.hpp"
#include "esp32-hal-gpio.h"
#include "esp32-hal.h"
#include <cstdint>

Buzzer::Buzzer(uint8_t pin):pin(pin) {
    pinMode(pin, OUTPUT);
}

void Buzzer::Buzz() {
    digitalWrite(this->pin, HIGH);
    delay(100);
    digitalWrite(this->pin, LOW);
}
