// Author: Ben Broce (BYU ECEn ELC)

// infrared module for reading or controlling the match start signals

// Note: HARDWARE?

// To modify hardware, register in:
// - pinDefs.h (pin number on MCU)
// - infrared.h, infrared.cpp (references)

#ifndef INFRARED_H
#define INFRARED_H

#include <stdbool.h>

// setup, clear infrared pins
void infraredInit();

// set infrared output
void infraredWrite(bool state);

// read infrared input
bool infraredRead();

#endif // INFRARED_H