// Author: Ben Broce (BYU ECEn ELC)

#include "infrared.h"
#include "pinDefs.h"
#include <Arduino.h>
#include <stdbool.h>

// setup, clear infrared pins
void infraredInit() {
  pinMode(IR_IN_PIN, INPUT_PULLUP);
  pinMode(IR_OUT_PIN, OUTPUT);
  digitalWrite(IR_OUT_PIN, LOW);
}

// set infrared output
void infraredWrite(bool state) { digitalWrite(IR_OUT_PIN, state); }

// read infrared input
bool infraredRead() { return !digitalRead(IR_IN_PIN); }