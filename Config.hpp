#ifndef _CONFIG_hpp
#define _CONFIG_hpp

#include "DFRobotDFPlayerMini.h"

//DFPlayer pins
const byte PLAYER_MODULE_RX = A4;
const byte PLAYER_MODULE_TX = A5;

//RC522 pins
const int RFID_MODULE_RST = 9;
const int RFID_MODULE_SS_SDA = 10;

const int RFID_MODULE_MOSI = 11;
const int RFID_MODULE_MISO = 12;
const int RFID_MODULE_SCK = 13;

//RGB LED pins
const int RGB_LED_RED = 3;
const int RGB_LED_GREEN = 5;
const int RGB_LED_BLUE = 6;

//Buzzer
const int BUZZER = 2;

//Other
const byte VOLUME_ROLL = A0;

const byte BUTTON_PLAY_PAUSE = A1;
const byte BUTTON_SHUFFLE = A2;
const byte BUTTON_MASTER_PROGRAMMER_MODE = A3;

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
