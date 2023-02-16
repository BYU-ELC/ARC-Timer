#ifndef PIN_DEFS
#define PIN_DEFS

// display control via shift registers (SRs) on SPI port
// D10 (CS)   -> all SRs latch pin
// D11 (COPI) -> SR 0 SIN pin
// D12 (CIPO) -> NC
// D13 (SCK)  -> all SRs SRCK pin
#define SHIFTREG_RCK_PIN 10

#endif // PIN_DEFS