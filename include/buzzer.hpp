#pragma once

#include <cstdint>
class Buzzer {
public:
    Buzzer(uint8_t pin);
    void Buzz();
private:
    uint8_t pin;
};
