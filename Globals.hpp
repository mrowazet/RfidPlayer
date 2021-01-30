#ifndef _GLOBALS_hpp
#define _GLOBALS_hpp

#include "Config.hpp"
#include <SoftwareSerial.h>
#include <MFRC522.h>
#include "DFRobotDFPlayerMini.h"


enum Mode
{
    Player,
    Programmer,
    MasterProgrammer
};

SoftwareSerial softwareSerial(PLAYER_MODULE_RX, PLAYER_MODULE_TX);
MFRC522 rfidModule(RFID_MODULE_SS_PIN, RFID_MODULE_RST_PIN);
DFRobotDFPlayerMini playerModule;

Mode currentMode = Mode::Player;

#endif
