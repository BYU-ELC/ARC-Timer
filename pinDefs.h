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
#define BTN_PAUSE_PIN 3
#define BTN_RESUME_PIN 4 // without delay
#define BTN_ADD_30_SEC_PIN 5
#define BTN_ADD_60_SEC_PIN 6
#define BTN_MISC_PIN 7

// infrared control signal pins
#define IR_IN_PIN A0
#define IR_OUT_PIN A1

// LED pins
#define A2 LED_5_PIN
#define A3 LED_4_PIN
#define A4 LED_3_PIN
#define A5 LED_2_PIN
#define A6 LED_1_PIN
#define A7 LED_GO_PIN

#endif // PIN_DEFS_H