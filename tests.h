/****************************************************************************************
// Byte Alignment Test

//[SETUP]

// initialize display (cleared on reset)
displayInit();
displayClear();

//[LOOP]

static uint8_t i = 1;
delay(1000);
Serial.println(i);
displayWriteBytes(i, i, i);
i = i << 1;
if (!i) {
        i = 1;
}
****************************************************************************************/

/****************************************************************************************
// Number Test

//[SETUP]

displayInit();
displayClear();

//[LOOP]

static uint8_t i = 0;
displayWriteTime(i, i, i);
i = (i + 1) % 10;
delay(1000);
****************************************************************************************/

/****************************************************************************************
// Timer Test

//[GLOBAL]

#define END_TIME_MS 183000
#define ONE_MINUTE_MS 60000
#define ONE_SECOND_MS 1000

uint32_t startTimeMS;
uint32_t elapsedTimeMS;
uint8_t tenSeconds;
uint8_t seconds;
uint8_t minutes;

//[SETUP]

displayInit();
displayClear();

startTimeMS = millis();
elapsedTimeMS = 0;
minutes = 0;
tenSeconds = 0;
seconds = 0;

//[LOOP]

elapsedTimeMS = millis() - startTimeMS;
if (elapsedTimeMS < END_TIME_MS) {
        seconds = (END_TIME_MS - elapsedTimeMS) / 1000;
        minutes = seconds / 60;
        seconds = seconds % 60;
        tenSeconds = seconds / 10;
        seconds = seconds % 10;
}

displayWriteTime(minutes, tenSeconds, seconds);
****************************************************************************************/