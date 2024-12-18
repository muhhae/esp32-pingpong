#include "ball.hpp"
#include "MD_Parola.h"
#include "global.hpp"
#include "vector2.hpp"
#include "math.h"
#include <cstdlib>
#include "device.hpp"

Ball::Ball(Vector2 position) : position(position) {
    this->position = Vector2(-6, p1.position.y);
    this->move = Vector2(0,0);
    this->updateRate = 1;
}

void Ball::HitCheck() {
    // Serial.printf("P1 X:%d Ball X:%d\n", p1.position.x, this->position.x);
    bool ballHitTheWall = this->position.y >= 3 || this->position.y <= -4;

    int deltaP1 = this->position.y - p1.position.y;
    int deltaP2 = this->position.y - p2.position.y;

    if (ballHitTheWall) {
        this->move.y *= -1;
    } else if (this->position.x == p1.position.x && abs(deltaP1) < 2 ) {
        this->move.x *= -1;
        this->move.y = p1.power != 1 ? 0 : deltaP1;
        this->updateRate = p1.power;
    } else if (this->position.x == p2.position.x && abs(deltaP2) < 2) {
        this->move.x *= -1;
        this->move.y = p2.power != 1 ? 0 : deltaP2;
        this->updateRate = p2.power;
    }
}

void Ball::ScoreCheck() {
    if (this->position.x < -8) {
        display.displayText("SCORED", PA_CENTER, 10, 500, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        mp.Switch(&tetris);
        while(!display.displayAnimate()) {
            mp.Play();
        }
        p2.score++;
        this->position = Vector2(-6, p1.position.y);
        this->move = Vector2(0,0);
        p1.service = true;
        this->updateRate = 1;
        mp.Switch(&mario_underworld);
    } else if (this->position.x > 7) {
        display.displayText("SCORED", PA_CENTER, 10, 500, PA_SCROLL_RIGHT, PA_SCROLL_RIGHT);
        mp.Switch(&tetris);
        while(!display.displayAnimate()) {
            mp.Play();
        }
        p1.score++;
        this->position = Vector2(5, p2.position.y);
        this->move = Vector2(0,0);
        p2.service = true;
        this->updateRate = 1;
        mp.Switch(&mario_underworld);
    }

}

void Ball::Update() {
    int current = millis();
    if (current - this->lastUpdate < 75 / updateRate) {
        return;
    }
    this->lastUpdate = current;
    HitCheck();
    ScoreCheck();
    this->position = this->position + this->move;
}

void Ball::Draw() {
    this->position.Draw();
}
