#pragma once

class Vector2 {
public:
    int x = 0,y = 0;
    Vector2(int x = 0, int y = 0): x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 operator*(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }
    Vector2 operator/(const Vector2& other) const {
        return Vector2(x / other.x, y / other.y);
    }
    Vector2 operator+(const float n) const {
        return Vector2(x + n, y + n);
    }
    Vector2 operator-(const float n) const {
        return Vector2(x - n, y - n);
    }
    Vector2 operator*(const float n) const {
        return Vector2(x * n, y * n);
    }
    Vector2 operator/(const float n) const {
        return Vector2(x / n, y / n);
    }
    Vector2 GlobalToDisplay() const;
    void Draw() const;
    void Clear() const;
};
