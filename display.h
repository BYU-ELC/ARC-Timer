// Author: Ben Broce (BYU ECEn ELC)

// Display module for driving large 7-segment displays over Arduino SPI bus via
// TPIC6B595 shift registers

//////////////////////////////
// 7-Segment Layout
// - number label is the output pin of the shift register,
//   and the index in the byte to write to the shift register
// - NOTE: a 1 turns the segment on (sink), a 0 turns it off (hi-Z)
//
//   _(1)_
//  |     |
// (6)   (2)
//  |     |
//   _(7)_
//  |     |
// (5)   (3)
//  |     |
//   _(4)_  .(0)
//////////////////////////////

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#define DISPLAY_SHIFTREG_MAX_RATE 10000000UL // max shift rate in Hz
#define DISPLAY_DIGIT_DP_MASK 0x01  // "." - 0000001 (right of digit with mask)
#define DISPLAY_DIGIT_CLR_MASK 0x00 // "" - 0000000 (clear byte)

// 7-segment control bytes for decimal digits
// ex: displayDigit[0] gives byte to write to shift register to display "0"
extern const uint8_t displayDigit[10];

// initialize the display hardware (call before writes)
void displayInit();

// write a time to the display in the format "M.SS"
void displayWriteTime(uint8_t min, uint8_t tenSec, uint8_t oneSec);

// write bytes to each display's shift register
void displayWriteBytes(uint8_t left, uint8_t middle, uint8_t right);

// turn off all display segments
void displayClear();

#endif // DISPLAY_H