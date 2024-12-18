#include "global.hpp"
#include "music.hpp"

Ball b = Ball(Vector2(0, 0));
Player p1 = Player(33, 19, Vector2(-8, 0));
Player p2 = Player(35, 22, Vector2(7, 0));
MusicPlayer mp = MusicPlayer();

Song mario = Song(mario_melody, mario_tempo, 78);
Song mario_underworld = Song(mario_melody, mario_tempo, 78);
Song tetris = Song(tetris_melody, tetris_tempo, 99);
