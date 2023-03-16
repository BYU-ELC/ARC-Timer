// Author: Ben Broce (BYU ECEn ELC)

// Main project sketch file for ARC Competition Timer
// - include all project libraries here for linking
// - basic setup() and loop() to call state machine functions

// libraries
#include <Arduino.h>
#include <SPI.h>

// modules
#include "buttons.h"
#include "display.h"
#include "infrared.h"
#include "leds.h"
#include "pinDefs.h"
#include "timerControl.h"

void setup() {
  // initialize hardware
  buttonsInit();
  displayInit();
  ledsInit();
  infraredInit();

  // initialize state machine
  timerControlInit();

  // serial debug
  Serial.begin(115200);
}

void loop() {
  // read inputs
  buttonsTick();

  // tick state machine
  timerControlTick();
}