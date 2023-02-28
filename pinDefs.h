#ifndef PIN_DEFS_H
#define PIN_DEFS_H

// display control via shift registers (SRs) on SPI port
// D10 (CS)   -> all SRs RCK latch pin
// D11 (COPI) -> SR 0 SIN pin
// D12 (CIPO) -> NC
// D13 (SCK)  -> all SRs SRCK pin
#define SHIFTREG_RCK_PIN 10

// control button pins
#define BTN_START_PIN 2 // with delay
#define BTN_STOP_PIN 3
#define BTN_RESUME_PIN 4 // without delay
#define BTN_ADD_30_SEC_PIN 5
#define BTN_ADD_60_SEC_PIN 6
#define BTN_MISC_PIN 7

// infrared control signal pins
#define IR_IN_PIN
#define IR_OUT_PIN

#endif // PIN_DEFS_H