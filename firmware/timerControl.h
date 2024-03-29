// Author: Ben Broce (BYU ECEn ELC)

// Timer control module to implement the main timer logic,
// calling modules to control hardware

#ifndef TIMER_CONTROL_H
#define TIMER_CONTROL_H

#define MATCH_TIME_MS 180000

void timerControlInit();

void timerControlTick();

#endif // TIMER_CONTROL_H