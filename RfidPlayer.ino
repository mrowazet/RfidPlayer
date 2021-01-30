#include <Arduino.h>

#include "Config.hpp"
#include "Initializer.hpp"
#include "Globals.hpp"
#include "PlayerMode.hpp"
#include "ProgrammerMode.hpp"
#include "MasterProgrammerMode.hpp"

Mode currentMode = Mode::Player;

SoftwareSerial softwareSerial(PLAYER_MODULE_RX, PLAYER_MODULE_TX);
MFRC522 rfidModule(RFID_MODULE_SS_SDA, RFID_MODULE_RST);
DFRobotDFPlayerMini playerModule;

PlayerMode playerMode(softwareSerial, 
                      rfidModule, 
                      playerModule, 
                      currentMode);
ProgrammerMode programmerMode(softwareSerial, 
                              rfidModule, 
                              playerModule, 
                              currentMode);
MasterProgrammerMode masterProgrammerMode(softwareSerial, 
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
    switch(currentMode)
    {
        case Mode::Player:
            playerMode.startProcessing(); 
            break;
        case Mode::Programmer:
            programmerMode.startProcessing();
            break;
        case Mode::MasterProgrammer:
            masterProgrammerMode.startProcessing(); 
            break;
    }
}
