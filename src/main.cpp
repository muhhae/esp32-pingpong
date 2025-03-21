#include <Arduino.h>
#include <cstdlib>
#include <ctime>

#include "MD_Parola.h"
#include "animation.hpp"
#include "device.hpp"
#include "esp32-hal-adc.h"
#include "esp32-hal-gpio.h"
#include "global.hpp"
#include "music.hpp"
#include "score.hpp"


void setup() {
    Setup();
    Intro();
    analogReadResolution(3);
    display.displayScroll("PRESS ANY BUTTON TO START...", PA_CENTER, PA_SCROLL_LEFT, 100);
    mp.Switch(&tetris);
    while (!digitalRead(p1.smashInput) && !digitalRead(p2.smashInput)) {
        mp.Play();
        if (display.displayAnimate()) {
            display.displayReset();
        }
    }
    delay(300);
    mp.Switch(&mario_underworld);
    p1.service = true;
}

int last = 0;
bool after_win = false;

void loop() {
    if (after_win) {
        delay(100);
        after_win = false;
    }
    mp.Play();
    int current = millis();

    b.Update();
    p1.CheckInput();
    p2.CheckInput();

    if (current - last < 100) {
        return;
    }

    last  = current;

    native_display.clear();
    p1.Draw();
    p2.Draw();
    b.Draw();

    RightRenderScore(p2.score, 9);
    LeftRenderScore(p1.score, -10);

    if (p1.score >= 11 && p1.score - p2.score >= 2) {
        delay(100);
        mp.Switch(&tetris);
        native_display.clear();
        display.displayText("P1 WIN", PA_CENTER, 50, 1000, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
        while (!digitalRead(p1.smashInput)&& !digitalRead(p2.smashInput)) {
            mp.Play();
            if (display.displayAnimate()) {
                display.displayReset();
            }
        }
        p1.score = 0;
        p2.score = 0;
        mp.Switch(&mario_underworld);
        after_win = true;
    }
    else if (p2.score >= 11 && p2.score - p1.score >= 2) {
        delay(100);
        mp.Switch(&tetris);
        native_display.clear();
        display.displayText("P2 WIN", PA_CENTER, 50, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        while (!digitalRead(p1.smashInput)&& !digitalRead(p2.smashInput)) {
            mp.Play();
            if (display.displayAnimate()) {
                display.displayReset();
            }
        }
        p1.score = 0;
        p2.score = 0;
        mp.Switch(&mario_underworld);
        after_win = true;
    } else if (p2.score >= 15 && p1.score >= 15) {
        delay(100);
        mp.Switch(&tetris);
        native_display.clear();
        display.displayText("TIE", PA_CENTER, 50, 1000, PA_SCROLL_UP, PA_SCROLL_UP);
        while (!digitalRead(p1.smashInput)&& !digitalRead(p2.smashInput)) {
            mp.Play();
            if (display.displayAnimate()) {
                display.displayReset();
            }
        }
        p1.score = 0;
        p2.score = 0;
        mp.Switch(&mario_underworld);
        after_win = true;
    }
}
