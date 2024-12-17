#include "score.hpp"
#include "HardwareSerial.h"
#include "vector2.hpp"
#include <cstdint>
#include <random>

Vector2 numPosition[] = {
    Vector2(0, 0),
    Vector2(1, 0),
    Vector2(2, 0),
    Vector2(0, -1),
    Vector2(2, -1),
    Vector2(0, -2),
    Vector2(1, -2),
    Vector2(2, -2),
    Vector2(0, -3),
    Vector2(2, -3),
    Vector2(0, -4),
    Vector2(1, -4),
    Vector2(2, -4),
};

uint16_t binaryRep[] = {
    0b1111110111111, // 0
    0b1001010010100, // 1
    0b1110111110111, // 2
    0b1111011110111, // 3
    0b1001011111101, // 4
    0b1111011101111, // 5
    0b1111111101111, // 6
    0b1001010010111, // 7
    0b1111111111111, // 8
    0b1111011111111  // 9
};

void RenderScore(uint8_t score, int x) {
    Vector2 position = Vector2(x, 2);

    int firstDigit = 0;
    int secondDigit = 0;

    if (score < 10) {
        secondDigit = score;
    } else {
        firstDigit = score / 10;
        secondDigit = score % 10;
    }

    int index = 0;
    for (const auto& p : numPosition) {
        if ((binaryRep[firstDigit] >> index) & 0x1) {
            (position + p).Draw();
        }
        index++;
    }
    position.x += 4;
    index = 0;
    for (const auto& p : numPosition) {
        if ((binaryRep[secondDigit] >> index) & 0x1) {
            (position + p).Draw();
        }
        index++;
    }
}
