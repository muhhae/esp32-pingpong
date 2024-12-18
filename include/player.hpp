#pragma  once

#include "vector2.hpp"
#include <cstdint>

class Player {
public:
    bool after_service = false;
    bool service = false;
    Vector2 position;
    Player(uint8_t dirInput, uint8_t smashInput, Vector2 position = Vector2());
    void Draw();
    void CheckInput();
    uint16_t score = 0;
    uint8_t power = 1;
    int last = 0;
    int ready = 0;
    uint8_t dirInput;
    uint8_t smashInput;
};
