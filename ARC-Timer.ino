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

  // setup LEDs
  pinMode(LED_5_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_GO_PIN, OUTPUT);

  buttonsInit();

  // serial debug
  Serial.begin(115200);
}

void loop() {
  buttonsTick();

  Serial.print(buttonsRead(BTN_START));
  Serial.print(buttonsRead(BTN_PAUSE));
  Serial.print(buttonsRead(BTN_RESUME));
  Serial.print(buttonsRead(BTN_ADD_30_SEC));
  Serial.print(buttonsRead(BTN_ADD_60_SEC));
  Serial.print(buttonsRead(BTN_MISC));
  Serial.println("");

  digitalWrite(LED_5_PIN, buttonsRead(BTN_START));
  digitalWrite(LED_4_PIN, buttonsRead(BTN_PAUSE));
  digitalWrite(LED_3_PIN, buttonsRead(BTN_RESUME));
  digitalWrite(LED_2_PIN, buttonsRead(BTN_ADD_30_SEC));
  digitalWrite(LED_1_PIN, buttonsRead(BTN_ADD_60_SEC));
  digitalWrite(LED_GO_PIN, buttonsRead(BTN_MISC));
}