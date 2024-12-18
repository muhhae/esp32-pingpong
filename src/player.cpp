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
    if (current - last >= 200 && (this-> power != 1 || after_service)) {
        if (this->position.x < 0) this->position.x -= 2;
        if (this->position.x > 0) this->position.x += 2;
        this->power = 1;
        after_service = false;
    }
    if (digitalRead(this->smashInput) && current >= ready) {
        int delta = this->position.x - b.position.x;
        delta /= abs(delta);
        this->last = current;
        if (this->position.x < 0) this->position.x += 2;
        if (this->position.x > 0) this->position.x -= 2;
        this->power = 8;
        this->ready = current + 1000;
        if (service) {
            this->power = 1;
            service = false;
            b.move = Vector2(delta, 0);
            after_service = true;
        }
    }
// Serial.printf("PlayerPos %d: %d %d\n", (this->dirInput == 35) + 1, this->position.x, this->position.y);
}
