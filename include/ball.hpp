#pragma once

#include "vector2.hpp"
class Ball {
public:
    Vector2 position;
    Ball(Vector2 position = Vector2());
    void Draw();
private:
};
