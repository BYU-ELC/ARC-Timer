// Author: Ben Broce (BYU ECEn ELC)

#include "buttons.h"
#include "pinDefs.h"
#include <Arduino.h>
#include <stdbool.h>
#include <stdint.h>

// helper function to tick a single button
static void buttonTick(uint8_t button);

// map of (button indices) -> (button pins)
// NOTE: order must match enum buttonsIndex_t in buttons.h
static const uint8_t buttonPins[BTN_COUNT] = {
    BTN_START_PIN,      BTN_PAUSE_PIN,      BTN_RESUME_PIN,
    BTN_ADD_30_SEC_PIN, BTN_ADD_60_SEC_PIN, BTN_SUB_15_SEC_PIN};

// debounce SM states (per button)
enum buttonsState_t {
  RELEASED_ST,
  DEBOUNCE_PRESSED_ST,
  PRESSED_ST,
  DEBOUNCE_RELEASED_ST
};
static enum buttonsState_t currentState[BTN_COUNT];

// start timestamps for debouncing timing on each button
static uint32_t debounceStartTime[BTN_COUNT];

// one-shot flags for each button
static bool oneShotFlag[BTN_COUNT];

// setup button state machine
void buttonsInit() {
  for (uint8_t button = 0; button < BTN_COUNT; ++button) {
    currentState[button] = RELEASED_ST;
    pinMode(buttonPins[button], INPUT_PULLUP);
    debounceStartTime[button] = 0;
    oneShotFlag[button] = false;
  }
}

// tick all button values
void buttonsTick() {
  for (uint8_t button = 0; button < BTN_COUNT; ++button) {
    buttonTick(button);
  }
}

// tick SM for a single button value
static void buttonTick(uint8_t button) {
  // state update
  switch (currentState[button]) {
  case RELEASED_ST:
    // if button pressed, start debouncing
    if (!digitalRead(buttonPins[button])) {
      currentState[button] = DEBOUNCE_PRESSED_ST;
      debounceStartTime[button] = millis();
    }
    break;
  case DEBOUNCE_PRESSED_ST:
    // if button remains pressed for the full debounce time,
    // register a press
    if (!digitalRead(buttonPins[button])) {
      if (((debounceStartTime[button] - millis()) > BTN_DEBOUNCE_PERIOD_MS)) {
        currentState[button] = PRESSED_ST;
      }
    } else {
      currentState[button] = RELEASED_ST;
    }
    break;
  case PRESSED_ST:
    // if button released, start debouncing
    if (digitalRead(buttonPins[button])) {
      currentState[button] = DEBOUNCE_RELEASED_ST;
      debounceStartTime[button] = millis();
    }
    break;
  case DEBOUNCE_RELEASED_ST:
    // if button remains released for the full debounce time,
    // register a release
    if (digitalRead(buttonPins[button])) {
      if (((debounceStartTime[button] - millis()) > BTN_DEBOUNCE_PERIOD_MS)) {
        currentState[button] = RELEASED_ST;
      }
    } else {
      currentState[button] = PRESSED_ST;
    }
    break;
  }

  // state action
  switch (currentState[button]) {
  case RELEASED_ST:
    // reset oneShotFlag on button release
    oneShotFlag[button] = false;
    break;
  case DEBOUNCE_PRESSED_ST:
    break;
  case PRESSED_ST:
    break;
  case DEBOUNCE_RELEASED_ST:
    break;
  }
}

// get debounced button value
bool buttonsRead(buttonsIndex_t button) {
  return (currentState[button] == PRESSED_ST);
}

// get debounced button value and lock buttonReadOneShot
// at the given button to false until button released (one-shot)
bool buttonsReadOneShot(buttonsIndex_t button) {
  bool value = (currentState[button] == PRESSED_ST) && !oneShotFlag[button];
  if (value) {
    oneShotFlag[button] = true;
  }
  return value;
}