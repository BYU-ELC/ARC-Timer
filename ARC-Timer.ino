// Author: Ben Broce (BYU ECEn ELC)

// Main project sketch file for ARC Competition Timer
// - include all project libraries here for linking
// - basic setup() and loop() to call state machine functions

// libraries
#include <Arduino.h>
#include <SPI.h>

// modules
#include "display.h"
#include "pinDefs.h"

#define END_TIME_MS 183000
#define ONE_MINUTE_MS 60000
#define ONE_SECOND_MS 1000

uint32_t startTimeMS;
uint32_t elapsedTimeMS;
uint8_t tenSeconds;
uint8_t seconds;
uint8_t minutes;

void setup() {
  // initialize display (cleared on reset)
  displayInit();
  displayClear();

  startTimeMS = millis();
  elapsedTimeMS = 0;
  minutes = 0;
  tenSeconds = 0;
  seconds = 0;

  // serial debug
  // Serial.begin(115200);
}

void loop() {
  elapsedTimeMS = millis() - startTimeMS;
  if (elapsedTimeMS < END_TIME_MS) {
    seconds = (END_TIME_MS - elapsedTimeMS) / 1000;
    minutes = seconds / 60;
    seconds = seconds % 60;
    tenSeconds = seconds / 10;
    seconds = seconds % 10;
  }

  displayWriteTime(minutes, tenSeconds, seconds);
}