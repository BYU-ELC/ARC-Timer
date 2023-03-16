// Author: Ben Broce (BYU ECEn ELC)

#include "leds.h"
#include "pinDefs.h"
#include <stdint.h>

// map of (LED indices) -> (LED pins)
// must be in the order to be lit
static const uint8_t ledPins[LED_COUNT] = {LED_5_PIN, LED_4_PIN, LED_3_PIN,
                                           LED_2_PIN, LED_1_PIN, LED_GO_PIN};

// setup, clear LED pins
void ledsInit() {
  for (uint8_t led = 0; led < LED_COUNT; ++led) {
    pinMode(ledPins[led], OUTPUT);
    digitalWrite(ledPins[led], LOW);
  }
}

// clear LEDs
void ledsClear() {
  for (uint8_t led = 0; led < LED_COUNT; ++led) {
    digitalWrite(ledPins[led], LOW);
  }
}

// light LEDs corresponding to the current countdown value
// 5 (1 lit), 4 (2 lit), ..., 1 (5 lit), 0 (6 lit, including green)
void ledsWriteCount(uint8_t countdownVal) {
  countdownVal = LED_COUNT - countdownVal;
  for (uint8_t led = 0; led < countdownVal; ++led) {
    digitalWrite(ledPins[led], HIGH);
  }
}