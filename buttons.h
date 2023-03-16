// Author: Ben Broce (BYU ECEn ELC)

// Buttons module for debouncing and selectively one-shotting an array of
// control buttons

// Note: all buttons should bridge between a digital pin (with an internal
// pull-up) and ground.
// To modify hardware, update BTN_COUNT and register buttons in:
// - pinDefs.h (pin number on MCU)
// - buttons.h (buttonsIndex_t)
// - buttons.cpp (buttonPins)

#ifndef BUTTONS_H
#define BUTTONS_H

#include <stdbool.h>

#define BTN_COUNT 6
#define BTN_DEBOUNCE_PERIOD_MS 50

// arrange buttons in order for indexing (not pin assignment)
// NOTE: order must match array buttonPins in buttons.cpp
enum buttonsIndex_t {
  BTN_START = 0,
  BTN_PAUSE = 1,
  BTN_RESUME = 2,
  BTN_ADD_30_SEC = 3,
  BTN_ADD_60_SEC = 4,
  BTN_MISC = 5
};

// setup button state machine
void buttonsInit();

// tick SM to update button values
// (asynchronous, call as frequently as possible)
void buttonsTick();

// get debounced button value
bool buttonsRead(buttonsIndex_t button);

// get debounced button value and lock buttonReadOneShot
// at the given button to false until button released (one-shot)
bool buttonsReadOneShot(buttonsIndex_t button);

#endif // BUTTONS_H