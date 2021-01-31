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
const int BUTTON_PRESSED_DELAY = 400;
const int DFPLAYER_EQ_MODE = DFPLAYER_EQ_NORMAL; 
/*possible options:
DFPLAYER_EQ_NORMAL
DFPLAYER_EQ_POP
DFPLAYER_EQ_ROCK
DFPLAYER_EQ_JAZZ
DFPLAYER_EQ_CLASSIC
DFPLAYER_EQ_BASS
*/

#endif
