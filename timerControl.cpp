#ifndef TIMER_CONTROL_H
#define TIMER_CONTROL_H

#include "timerControl.h"
#include "display.h"

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
    Serial.println("Invalid State\n");
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
    Serial.println("Invalid State\n");
  }
}

#endif // TIMER_CONTROL_H