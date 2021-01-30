#include <Arduino.h>

#include "Config.hpp"
#include "Initializer.hpp"
#include "Globals.hpp"
#include "PlayerMode.hpp"
#include "ProgrammerMode.hpp"

Mode currentMode = Mode::Player;

SoftwareSerial softwareSerial(PLAYER_MODULE_RX, PLAYER_MODULE_TX);
MFRC522 rfidModule(RFID_MODULE_SS_PIN, RFID_MODULE_RST_PIN);
DFRobotDFPlayerMini playerModule;

PlayerMode playerMode(softwareSerial, 
                      rfidModule, 
                      playerModule,
                      currentMode);
ProgrammerMode programmerMode(softwareSerial, 
                              rfidModule, 
                              playerModule,
                              currentMode);

void setup() 
{
    Initializer initializer(softwareSerial, 
                            rfidModule, 
                            playerModule);
    initializer.init();                               
}

void loop() 
{
    if(currentMode == Mode::Player)
    {
        playerMode.process();
    }
    else
    {
        programmerMode.process();  
    }
    currentMode = Mode::Programmer;
}
