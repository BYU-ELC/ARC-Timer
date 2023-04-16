// Author: Ben Broce (BYU ECEn ELC)

#include "timerControl.h"
#include "buttons.h"
#include "display.h"
#include "infrared.h"
#include "leds.h"
#include <Arduino.h>
#include <stdint.h>

// #define TIMER_CONTROL_DEBUG
#define MS_PER_SECOND 1000L
#define MS_PER_15_SECONDS 15000L
#define MS_PER_30_SECONDS 30000L
#define MS_PER_60_SECONDS 60000L

// helper functions
static int32_t currentTimeMS();
static void updateTimerTargetMS();

enum timerControlState_t {
  PAUSE_ST, // stop timer (timer value on display)
  START_ST, // countdown on LEDs until timer starts (timer value on display)
  RUN_ST    // run timer (timer value on display)
};
static enum timerControlState_t currentState;

// time to count down from (full match time, time remaining @ pause)
// (add increments, sub decrements)
static int32_t timerTargetMS;
// millis() timestamp of last timer start
static uint32_t timerStartTimeMS;
// millis() timestamp for small interval timing
static uint32_t intervalStartTimeMS;
// START_ST countdown value
static uint8_t countDownVal;

// initialize timer control state machine
void timerControlInit() {
  currentState = PAUSE_ST;
  timerTargetMS = MATCH_TIME_MS;
  timerStartTimeMS = 0;
  intervalStartTimeMS = 0;
  countDownVal = LED_COUNT;
}

// tick timer control state machine
void timerControlTick() {
  // state update
  switch (currentState) {

  case PAUSE_ST:
    if (buttonsReadOneShot(BTN_START) || infraredRead()) {
      currentState = START_ST;
      intervalStartTimeMS = millis();
      countDownVal = (LED_COUNT - 1);
    } else if (buttonsReadOneShot(BTN_RESUME)) {
      currentState = RUN_ST;
      timerStartTimeMS = millis();
    }
    break;

  case START_ST:
    if (buttonsReadOneShot(BTN_PAUSE)) {
      currentState = PAUSE_ST;
      ledsClear();
    } else if (countDownVal == 0) {
      currentState = RUN_ST;
      ledsClearAllButGo();
      timerStartTimeMS = millis();
    }
    break;

  case RUN_ST:
    if (buttonsReadOneShot(BTN_PAUSE) || (currentTimeMS() <= 0)) {
      currentState = PAUSE_ST;
      ledsClear();
      // set new timer target to time remaining
      timerTargetMS -= (millis() - timerStartTimeMS);
    }
    break;

  default:
#ifdef TIMER_CONTROL_DEBUG
    Serial.println("Invalid State\n");
#endif
    break;
  }

  // state action
  switch (currentState) {

  case PAUSE_ST:
    updateTimerTargetMS();
    displayWriteTimeMS(timerTargetMS);
    break;

  case START_ST:
    if ((millis() - intervalStartTimeMS) >= MS_PER_SECOND) {
      countDownVal--;
      intervalStartTimeMS = millis();
    }
    ledsWriteCount(countDownVal);
    updateTimerTargetMS();
    displayWriteTimeMS(timerTargetMS);
    break;

  case RUN_ST:
    updateTimerTargetMS();
    displayWriteTimeMS(currentTimeMS());
    break;

  default:
#ifdef TIMER_CONTROL_DEBUG
    Serial.println("Invalid State\n");
#endif
    break;
  }
}

static int32_t currentTimeMS() {
  // current time = (current target) - (current runtime)
  return (timerTargetMS - (millis() - timerStartTimeMS));
}

static void updateTimerTargetMS() {
  if (buttonsReadOneShot(BTN_ADD_30_SEC)) {
    timerTargetMS += MS_PER_30_SECONDS;
  }
  if (buttonsReadOneShot(BTN_ADD_60_SEC)) {
    timerTargetMS += MS_PER_60_SECONDS;
  }
  if (buttonsReadOneShot(BTN_SUB_15_SEC)) {
    timerTargetMS -= MS_PER_15_SECONDS;
  }
}