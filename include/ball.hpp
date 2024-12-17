#pragma once

#include "vector2.hpp"
class Ball {
public:
    Vector2 position;
    Vector2 move;
    Ball(Vector2 position = Vector2());
    void Draw();
    void Update();
    void HitCheck();
    void ScoreCheck();
    int lastUpdate = 0;
    int updateRate = 1;
private:
};
