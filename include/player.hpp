#pragma  once

#include "vector2.hpp"
#include <cstdint>

class Player {
public:
    Vector2 position;
    Player(uint8_t dirInput, uint8_t smashInput, Vector2 position = Vector2());
    void Draw();
    void CheckInput();
private:
    uint8_t dirInput;
    uint8_t smashInput;
};
