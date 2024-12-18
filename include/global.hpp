#pragma once

#include "ball.hpp"
#include "buzzer.hpp"
#include "player.hpp"
#include <cstdint>
#include "music.hpp"

extern Ball b;
extern Player p1;
extern Player p2;
static uint8_t score = 0;
extern Buzzer buzzer;
extern MusicPlayer mp;

extern Song mario;
extern Song mario_underworld;
extern Song tetris;
