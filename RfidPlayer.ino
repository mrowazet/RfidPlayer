#include <Arduino.h>

#include "Globals.hpp"
#include "Config.hpp"
#include "Initializer.hpp"
#include "Buzzer.hpp"
#include "RgbLed.hpp"
#include "UserNotifier.hpp"
#include "PlayerMode.hpp"
#include "ProgrammerMode.hpp"
#include "MasterProgrammerMode.hpp"

Mode currentMode = Mode::Player;

SoftwareSerial softwareSerial(PLAYER_MODULE_RX, PLAYER_MODULE_TX);
MFRC522 rfidModule(RFID_MODULE_SS_SDA, RFID_MODULE_RST);
DFRobotDFPlayerMini playerModule;

UserNotifier userNotifier(Buzzer(BUZZER),
                          RgbLed(RGB_LED_RED,
                                 RGB_LED_GREEN,
                                 RGB_LED_BLUE));

PlayerMode playerMode(softwareSerial, 
                      rfidModule, 
                      playerModule,
                      userNotifier, 
                      currentMode);
                      
ProgrammerMode programmerMode(softwareSerial, 
                              rfidModule, 
                              playerModule, 
                              userNotifier,
                              currentMode);
                              
MasterProgrammerMode masterProgrammerMode(softwareSerial, 
                                          rfidModule, 
                                          playerModule,
                                          userNotifier,
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
