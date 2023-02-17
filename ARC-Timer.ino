// Author: Ben Broce (BYU ECEn ELC)

// Main project sketch file for ARC Competition Timer
// - include all project libraries here for linking
// - basic setup() and loop() to call state machine functions

// libraries
#include <Arduino.h>
#include <SPI.h>

// modules
#include "display.h"

void setup() {
  // initialize display (cleared on reset)
  displayInit();
}

void loop() {}