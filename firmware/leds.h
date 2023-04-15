// Author: Ben Broce (BYU ECEn ELC)

// LEDs module for controlling the countdown LEDs via an integer countdown

// Note: all LEDs anodes should be connected to a digital pin via a
// current-limiting resistor, and all cathodes should be connected to ground.

// To modify hardware, update LED_COUNT and register LEDs in:
// - pinDefs.h (pin number on MCU)
// - leds.cpp (ledPins)

#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

#define LED_COUNT 6

// setup, clear LED pins
void ledsInit();

// clear LEDs
void ledsClear();

// clear LEDs except green
void ledsClearAllButGo();

// light LEDs corresponding to the current countdown value
// 5 (1 lit), 4 (2 lit), ..., 1 (5 lit), GO (6 lit, including green)
void ledsWriteCount(uint8_t countdownVal);

#endif // LEDS_H