#include <Arduino.h>
#include <cstdlib>
#include <ctime>

#include "ball.hpp"
#include "device.hpp"
#include "esp32-hal.h"
#include "player.hpp"
#include "vector2.hpp"

void setup() {
    Setup();
    // Intro();
    analogReadResolution(12);
    analogSetAttenuation(ADC_0db);
    std::srand(std::time(0));
}

Ball n = Ball(Vector2(0, 0));
Player p1 = Player(0, 0, Vector2(-8, 0));
Player p2 = Player(0, 0, Vector2(7, 0));

void loop() {
    n.Draw();
    p1.Draw();
    p2.Draw();
    delay(100);
    native_display.clear();
    n.position = n.position + Vector2(std::rand()%3-1, std::rand()%3-1);
    if (abs(n.position.x) > 15 || abs(n.position.y) > 3) {
        n.position = Vector2(0, 0);
    }
    p1.position = p1.position + Vector2(0, std::rand()%3-1);
    if (abs(p1.position.y) > 3) {
        p1.position.y = 0;
    }
    p2.position = p2.position + Vector2(0, std::rand()%3-1);
    if (abs(p2.position.y) > 3) {
        p2.position.y = 0;
    }
}
