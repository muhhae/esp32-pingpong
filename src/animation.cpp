#include "device.hpp"
#include <cstdio>
#include "animation.hpp"
#include "global.hpp"

void Intro() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 * MAX_DEVICES; j++) {
            native_display.setPoint(i, j, HIGH);
            delay(20);
            native_display.setPoint(i, j, LOW);
        }
        delay(20);
    }
    native_display.clear();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 * MAX_DEVICES; j++) {
            native_display.setPoint(i, j, HIGH);
            native_display.setPoint(i - 1, j, LOW);
        }
        delay(20);
    }
    native_display.clear();
    for (int i = 8; i >= 0; i--) {
        for (int j = 8 * MAX_DEVICES; j >= 0; j--) {
            native_display.setPoint(i, j, HIGH);
        }
        delay(20);
    }
    native_display.clear();
    for (int j = 0; j < 8 * MAX_DEVICES; j++) {
        for (int i = 0; i < 8; i++) {
            native_display.setPoint(i, j, HIGH);
            native_display.setPoint(i, j - 1, LOW);
        }
        delay(20);
    }
    native_display.clear();
    for (int j = 8 * MAX_DEVICES; j >= 0; j--) {
        for (int i = 8; i >= 0; i--) {
            native_display.setPoint(i, j, HIGH);
        }
        delay(20);
    }
    native_display.clear();
    display.displayScroll("Muhammad Haekal Muhyidin Al-Araby 5024221030", PA_CENTER, PA_SCROLL_LEFT, 20);
    while(!display.displayAnimate());
    display.displayScroll("PING PONG", PA_CENTER, PA_SCROLL_RIGHT, 20);
    while(!display.displayAnimate());
}
