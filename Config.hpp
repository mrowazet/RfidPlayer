#ifndef _CONFIG_hpp
#define _CONFIG_hpp

#include "DFRobotDFPlayerMini.h"

const int RFID_MODULE_RST_PIN = 9;
const int RFID_MODULE_SS_PIN = 10;

const byte VOLUME_ROLL = A0;

const byte BUTTON_PLAY_PAUSE = A1;
const byte BUTTON_SHUFFLE = A2;
const byte BUTTON_MASTER_PROGRAMMER_MODE = A3;

const byte PLAYER_MODULE_RX = A4;
const byte PLAYER_MODULE_TX = A5;

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
