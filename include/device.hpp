#pragma once

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <cstdint>

constexpr MD_MAX72XX::moduleType_t HARDWARE_TYPE = MD_MAX72XX::FC16_HW;
constexpr uint8_t MAX_DEVICES = 4;
constexpr uint8_t CS_PIN = 12;
constexpr uint8_t DIN_PIN = 13;
constexpr uint8_t CLK_PIN = 14;
constexpr uint16_t SPEED = 100;

extern MD_Parola display;
extern MD_MAX72XX native_display;

void Setup();
