#include <Arduino.h>
#include <cstdlib>
#include <ctime>

#include "MD_Parola.h"
#include "animation.hpp"
#include "device.hpp"
#include "esp32-hal-adc.h"
#include "esp32-hal-gpio.h"
#include "global.hpp"
#include "score.hpp"


void setup() {
    Setup();
    Intro();
    analogReadResolution(3);
    display.displayScroll("PRESS ANY BUTTON TO START...", PA_CENTER, PA_SCROLL_LEFT, 100);
    while (!digitalRead(p1.smashInput) && !digitalRead(p2.smashInput)) {
        if (display.displayAnimate()) {
            display.displayReset();
        }
    }
}

int last = 0;

void loop() {
    int current = millis();

    b.Update();
    p1.CheckInput();
    p2.CheckInput();

    if (current - last < 50) {
        return;
    }

    last  = current;

    native_display.clear();
    p1.Draw();
    p2.Draw();
    b.Draw();

    RenderScore(p2.score, 9);
    RenderScore(p1.score, -16);

    if (p1.score >= 11 && p1.score - p2.score >= 2) {
        native_display.clear();
        display.displayText("P1 WIN", PA_CENTER, 50, 1000, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
        while (!digitalRead(p1.smashInput)&& !digitalRead(p2.smashInput)) {
            if (display.displayAnimate()) {
                display.displayReset();
            }
        }
        p1.score = 0;
        p2.score = 0;
    }
    else if (p2.score >= 11 && p2.score - p1.score >= 2) {
        native_display.clear();
        display.displayText("P2 WIN", PA_CENTER, 50, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        while (!digitalRead(p1.smashInput)&& !digitalRead(p2.smashInput)) {
            if (display.displayAnimate()) {
                display.displayReset();
            }
        }
        p1.score = 0;
        p2.score = 0;
    } else if (p2.score >= 15 && p1.score >= 15) {
        native_display.clear();
        display.displayText("TIE", PA_CENTER, 50, 1000, PA_SCROLL_UP, PA_SCROLL_UP);
        while (!digitalRead(p1.smashInput)&& !digitalRead(p2.smashInput)) {
            if (display.displayAnimate()) {
                display.displayReset();
            }
        }
        p1.score = 0;
        p2.score = 0;
    }
}
