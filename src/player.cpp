#include "global.hpp"
#include "esp32-hal-adc.h"
#include "esp32-hal-gpio.h"
#include "esp32-hal.h"
#include "player.hpp"

Player::Player(uint8_t dirInput, uint8_t smashInput, Vector2 position)
    : dirInput(dirInput), smashInput(smashInput), position(position) {
    pinMode(smashInput, INPUT_PULLUP);
}

void Player::Draw() {
    this->position.Draw();
    (this->position + Vector2(0, 1)).Draw();
    (this->position + Vector2(0, -1)).Draw();
}

void Player::CheckInput() {
    this->position.y = analogRead(this->dirInput) - 4;
    if (this->position.y > 2) this-> position.y = 2;
    else if (this->position.y < -3) this-> position.y = -3;

    if (this->service) {
        b.position.y = this->position.y;
    }

    int current = millis();
    if (current - last >= 200 && this-> power != 1) {
        if (this->position.x < 0) this->position.x -= 2;
        if (this->position.x > 0) this->position.x += 2;
        this->power = 1;
    }
    if (digitalRead(this->smashInput) && current >= ready) {
        this->last = current;
        if (this->position.x < 0) this->position.x += 2;
        if (this->position.x > 0) this->position.x -= 2;
        this->power = 15;
        this->ready = current + 1000;
        if (service) {
            service = false;
            b.move = Vector2(b.position.x - this->position.x, 0);
        }
    }
// Serial.printf("PlayerPos %d: %d %d\n", (this->dirInput == 35) + 1, this->position.x, this->position.y);
}
