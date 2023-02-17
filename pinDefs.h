#ifndef PIN_DEFS_H
#define PIN_DEFS_H

// display control via shift registers (SRs) on SPI port
// D10 (CS)   -> all SRs RCK latch pin
// D11 (COPI) -> SR 0 SIN pin
// D12 (CIPO) -> NC
// D13 (SCK)  -> all SRs SRCK pin
#define SHIFTREG_RCK_PIN 10

#endif // PIN_DEFS_H