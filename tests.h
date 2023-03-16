/****************************************************************************************
// Byte Alignment Test //

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
// Number Test //

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
// Timer Test //

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

/****************************************************************************************
// Buttons & LEDs Test //

//[SETUP]

// setup LEDs
pinMode(LED_5_PIN, OUTPUT);
pinMode(LED_4_PIN, OUTPUT);
pinMode(LED_3_PIN, OUTPUT);
pinMode(LED_2_PIN, OUTPUT);
pinMode(LED_1_PIN, OUTPUT);
pinMode(LED_GO_PIN, OUTPUT);
// setup buttons
buttonsInit();
// serial debug
Serial.begin(115200);

//[LOOP]

buttonsTick();

Serial.print(buttonsRead(BTN_START));
Serial.print(buttonsRead(BTN_PAUSE));
Serial.print(buttonsRead(BTN_RESUME));
Serial.print(buttonsRead(BTN_ADD_30_SEC));
Serial.print(buttonsRead(BTN_ADD_60_SEC));
Serial.print(buttonsRead(BTN_MISC));
Serial.println("");

digitalWrite(LED_5_PIN, buttonsRead(BTN_START));
digitalWrite(LED_4_PIN, buttonsRead(BTN_PAUSE));
digitalWrite(LED_3_PIN, buttonsRead(BTN_RESUME));
digitalWrite(LED_2_PIN, buttonsRead(BTN_ADD_30_SEC));
digitalWrite(LED_1_PIN, buttonsRead(BTN_ADD_60_SEC));
digitalWrite(LED_GO_PIN, buttonsRead(BTN_MISC));
****************************************************************************************/