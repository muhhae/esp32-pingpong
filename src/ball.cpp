#include "ball.hpp"
#include "vector2.hpp"

Ball::Ball(Vector2 position) : position(position) {

}

void Ball::Draw() {
    this->position.Draw();
    // (this->position + Vector2(1, 0)).Draw();
    // (this->position + Vector2(0, 1)).Draw();
    // (this->position + Vector2(0, -1)).Draw();
    // (this->position + Vector2(-1, 0)).Draw();
}
