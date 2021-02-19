#ifndef _CONFIG_hpp
#define _CONFIG_hpp

#include "Globals.hpp"
#include "DFRobotDFPlayerMini.h"

//DFPlayer pins
const AnalogPin PLAYER_MODULE_RX = A4;
const AnalogPin PLAYER_MODULE_TX = A5;

//RC522 pins
const Pin RFID_MODULE_RST = 9;
const Pin RFID_MODULE_SS_SDA = 10;

const Pin RFID_MODULE_MOSI = 11;
const Pin RFID_MODULE_MISO = 12;
const Pin RFID_MODULE_SCK = 13;

//RGB LED pin
const Pin RGB_LED_CONTROL = 5;

//Buzzer pin
const Pin BUZZER = 4;

//Other
const AnalogPin VOLUME_ROLL = A0;

const AnalogPin BUTTON_PLAY_PAUSE = A1;
const AnalogPin BUTTON_SHUFFLE = A2;
const AnalogPin BUTTON_MASTER_PROGRAMMER_MODE = A3;

//Constants
const int NUM_OF_RGB_LEDS = 1;

const byte MAX_NUM_OF_TRACKS = 100;

const byte MASTER_CARD_CODE = 254;
const byte DATA_BLOCK_NUMBER = 62;
const int NO_NEW_CARD_DETECTED = 0;

const int DEBOUNCE_INTERVAL = 5;

const int VOLUME_UPDATE_INTERVAL_IN_MS = 250;
const int ATTEMPT_CARD_WRITE_TIMEOUT_IN_MS = 10000;
const int USER_INPUT_TIMEOUT_IN_MS = 20000;
const int COLOR_MINOR_UPDATE_INTERVAL_IN_MS = 200;
const int COLOR_MAJOR_UPDATE_INTERVAL_IN_MS = 5000;
const int COLOR_UPDATE_STEP = 10;

const int SHORT_BEEP_DURATION = 400;
const int LONG_BEEP_DURATION = 900;
const int ERROR_BEEP_DURATION = 1500;
const int DOUBLE_BEEP_DURATION = 300;
const int DOUBLE_BEEP_GAP = DOUBLE_BEEP_DURATION + 150;
const int DOUBLE_BEEP_TOTAL_DURATION = DOUBLE_BEEP_GAP + DOUBLE_BEEP_DURATION;

const int CARD_READ_BEEP_WITH_OFFSET = SHORT_BEEP_DURATION + 100;
const int CONFIRM_BEEP_WITH_OFFSET = DOUBLE_BEEP_TOTAL_DURATION + 100;

const int BEEP_FREQ = 800;
const int ERROR_BEEP_FREQ = 200;

const byte MIN_VALUE_FOR_MOST_INTENSIVE_COLOR = 225;
const byte MAX_VALUE_FOR_LESS_INTENSIVE_COLORS = 80;

const int DFPLAYER_EQ_MODE = DFPLAYER_EQ_NORMAL; 
/*possible options:
DFPLAYER_EQ_NORMAL
DFPLAYER_EQ_POP
DFPLAYER_EQ_ROCK
DFPLAYER_EQ_JAZZ
DFPLAYER_EQ_CLASSIC
DFPLAYER_EQ_BASS
*/

//Colors
const Color COLOR_NONE(0, 0 ,0);
const Color COLOR_RED(255, 0, 0);
const Color COLOR_GREEN(0, 255, 0);
const Color COLOR_BLUE(0, 0, 255);
const Color COLOR_CYAN(0, 255, 255);
const Color COLOR_MAGENTA(255, 0, 255);
const Color COLOR_YELLOW(255, 255, 0);

#endif
