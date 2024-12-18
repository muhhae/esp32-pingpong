#include "device.hpp"
#include "HardwareSerial.h"

MD_Parola display = MD_Parola(HARDWARE_TYPE, DIN_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
MD_MAX72XX native_display = MD_MAX72XX(HARDWARE_TYPE, DIN_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void Setup() {
    native_display.begin();
    native_display.clear();
    native_display.control(MD_MAX72XX::INTENSITY, 0);

    display.begin();
    display.setIntensity(10);
    display.displayClear();

    Serial.begin(9600);
}
