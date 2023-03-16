#include "timerControl.h"
#include "buttons.h"
#include "display.h"
#include <Arduino.h>

// #TIMER_CONTROL_DEBUG

enum timerControlState_t { WAIT_ST, START_ST, COUNTDOWN_ST, PAUSE_ST, STOP_ST };
static enum timerControlState_t currentState;

void timerControlInit() { currentState = WAIT_ST; }

void timerControlTick() {
  // state update
  switch (currentState) {
  case WAIT_ST:
    if (0 == 0) {
    }
    break;

  case START_ST:
    if (0 == 0) {
    }
    break;

  case COUNTDOWN_ST:
    if (0 == 0) {
    }
    break;

  case PAUSE_ST:
    if (0 == 0) {
    }
    break;

  case STOP_ST:
    if (0 == 0) {
    }
    break;

  default:
#ifdef TIMER_CONTROL_DEBUG
    Serial.println("Invalid State\n");
#else
    break;
#endif
  }

  // state action
  switch (currentState) {
  case WAIT_ST:
    if (0 == 0) {
    }
    break;

  case START_ST:
    if (0 == 0) {
    }
    break;

  case COUNTDOWN_ST:
    if (0 == 0) {
    }
    break;

  case PAUSE_ST:
    if (0 == 0) {
    }
    break;

  case STOP_ST:
    if (0 == 0) {
    }
    break;

  default:
#ifdef TIMER_CONTROL_DEBUG
    Serial.println("Invalid State\n");
#else
    break;
#endif
  }
}