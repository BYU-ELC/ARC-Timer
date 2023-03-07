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

uint8_t i;

void setup() {
  // initialize display (cleared on reset)
  displayInit();
  displayClear();
  i = 1;

  // init test LED
  pinMode(LED_2_PIN, OUTPUT);

  // serial debug
  Serial.begin(115200);
}

void loop() {
  delay(1000);
  displayWriteBytes(i, i, i);
  Serial.println(i);
  i = i << 1;
  if (!i) {
    i = 1;
  }
  digitalWrite(LED_2_PIN, HIGH);
}