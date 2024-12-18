#pragma once

#include "HardwareSerial.h"
#include "esp32-hal-ledc.h"
#include "esp32-hal.h"
#include <strings.h>
#include <sys/types.h>
#include "song.hpp"




class MusicPlayer {
public:
    MusicPlayer() {
        ledcAttachPin(32, 0);
        ledcSetup(0, 2048, 12);
    }
    void Switch(Song* song) {
        this->song.tempo = song->tempo;
        this->song.melody = song->melody;
        this->song.size = song->size;
        index = 0;
        this->Start();
    }
    void Start() {
        if (song.size <= 0 || song.melody == nullptr || song.tempo == nullptr) return;
        ledcWriteTone(0, song.melody[0]);
        this->index = 0;
        this->last = millis();
    }
    void Play() {
        if (song.size <= 0 || song.melody == nullptr || song.tempo == nullptr) return;
        int current = millis();
        int duration = 1000 / abs(song.tempo[index]);
        if (tetris_tempo[index] < 0) {
            duration *= 1.5;
        }
        if (current - this->last < duration) return;
        last = current;
        this->index++;
        if (index > song.size - 1) index = 0;
        ledcWriteTone(0, song.melody[this->index]);
    }
private:
    int index = 0;
    int last;
    Song song = Song(nullptr, nullptr, 0);
};
