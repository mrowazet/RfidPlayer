#include <Arduino.h>

#include "Globals.hpp"
#include "Config.hpp"
#include "ButtonsHandler.hpp"
#include "UserNotifier.hpp"
#include "PlayerMode.hpp"
#include "ProgrammerMode.hpp"
#include "MasterProgrammerMode.hpp"
#include "RfidModule.hpp"
#include "PlayerModule.hpp"

Mode currentMode = Mode::Player;

ButtonsHandler* buttonsHandler;
UserNotifier* userNotifier;

RfidModule* rfidModule;
PlayerModule* playerModule;

PlayerMode* playerMode;                  
ProgrammerMode* programmerMode;                          
MasterProgrammerMode* masterProgrammerMode; 
                                                                       
void setup() 
{
    Serial.begin(115200);
    print("Start RFID Player...");

    buttonsHandler = new ButtonsHandler(BUTTON_PLAY_PAUSE, BUTTON_SHUFFLE, BUTTON_MASTER_PROGRAMMER_MODE);
    userNotifier = new UserNotifier(BUZZER, RGB_LED_CONTROL);

    rfidModule = new RfidModule(RFID_MODULE_SS_SDA, RFID_MODULE_RST, *userNotifier);
    playerModule = new PlayerModule(PLAYER_MODULE_RX, PLAYER_MODULE_TX, VOLUME_ROLL, *userNotifier);

    playerMode = new PlayerMode(*buttonsHandler, *rfidModule, *playerModule, *userNotifier, currentMode);                  
    programmerMode = new ProgrammerMode(*buttonsHandler, *rfidModule, *playerModule, *userNotifier, currentMode);                          
    masterProgrammerMode = new MasterProgrammerMode(*buttonsHandler, *rfidModule, *playerModule, *userNotifier, currentMode);    
}

void loop() 
{
    switch(currentMode)
    {
        case Mode::Player:
            playerMode->startProcessing(); 
            break;
        case Mode::Programmer:
            programmerMode->startProcessing();
            break;
        case Mode::MasterProgrammer:
            masterProgrammerMode->startProcessing(); 
            break;
    }
}
