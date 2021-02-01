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

//RGB LED pins
const Pin RGB_LED_RED = 3;
const Pin RGB_LED_GREEN = 5;
const Pin RGB_LED_BLUE = 6;

//Buzzer
const Pin BUZZER = 2;

//Other
const AnalogPin VOLUME_ROLL = A0;

const AnalogPin BUTTON_PLAY_PAUSE = A1;
const AnalogPin BUTTON_SHUFFLE = A2;
const AnalogPin BUTTON_MASTER_PROGRAMMER_MODE = A3;

//Constants
const int MASTER_CARD_CODE = 9999;
const int BUTTON_PRESSED_DELAY = 400;
const int SHORT_BEEP_DURATION = 400;
const int LONG_BEEP_DURATION = 900;
const int DOUBLE_BEEP_DURATION = 300;
const int DOUBLE_BEEP_GAP = 100;
const int BEEP_FREQ = 80;
const int ERROR_BEEP_FREQ = 10;

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
const Color COLOR_RASPBERRY(255, 255, 125);
const Color COLOR_CYAN(0, 255, 255);
const Color COLOR_MAGENTA(255, 0, 255);
const Color COLOR_YELLOW(255, 255, 0);
const Color COLOR_ORANGE(255,165,0);
const Color COLOR_WHITE(255, 255, 255);

#endif
