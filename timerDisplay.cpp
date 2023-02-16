// Author: Ben Broce (BYU ECEn ELC)

#include "timerDisplay.h"
#include "pinDefs.h"
#include <SPI.h>
#include <stdint.h>

// 7-segment control bytes for decimal digits
// ex: SEG_DIGIT[0] gives byte to write to shift register to display "0"
const uint8_t displayDigit[10] = {
    0x7E, // "0" - 01111110
    0x0C, // "1" - 00001100
    0xB6, // "2" - 10110110
    0x9E, // "3" - 10011110
    0xCC, // "4" - 11001100
    0xDA, // "5" - 11011010
    0xFA, // "6" - 11111010
    0x0E, // "7" - 00001110
    0xFE, // "8" - 11111110
    0xDE  // "9" - 11011110
};

// initialize the display hardware (call before writes)
void displayInit() {
  // release register values -> 7-seg output
  pinMode(SHIFTREG_RCK_PIN, OUTPUT);
  digitalWrite(SHIFTREG_RCK_PIN, HIGH);
  // init SPI hardware
  // (set max data rate, MSB first, and
  // SPI_MODE1: clock idles low, bit write on rising clk)
  SPI.beginTransaction(
      SPISettings(DISPLAY_SHIFTREG_MAX_RATE, MSBFIRST, SPI_MODE1));
}

// write bytes to each display's shift register
void displayWriteBytes(uint8_t left, uint8_t middle, uint8_t right) {
  // hold 7-seg output while writing data
  digitalWrite(SHIFTREG_RCK_PIN, LOW);

  // write bytes in order: left, middle, right digit
  SPI.transfer(left);
  SPI.transfer(middle);
  SPI.transfer(right);

  // release reg values -> 7-seg to display new values
  digitalWrite(SHIFTREG_RCK_PIN, HIGH);
}

// write a time to the display in the format "M.SS"
void displayWriteTime(uint8_t min, uint8_t tenSec, uint8_t oneSec) {
  displayWriteBytes((displayDigit[min] | DISPLAY_DIGIT_DP_MASK),
                    displayDigit[tenSec], displayDigit[oneSec]);
}

// turn off all display segments
void displayClear() {
  displayWriteBytes(DISPLAY_DIGIT_CLR_MASK, DISPLAY_DIGIT_CLR_MASK,
                    DISPLAY_DIGIT_CLR_MASK);
}