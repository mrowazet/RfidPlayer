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

ButtonsHandler buttonsHandler(BUTTON_PLAY_PAUSE, BUTTON_SHUFFLE, BUTTON_MASTER_PROGRAMMER_MODE);
UserNotifier userNotifier(BUZZER, RGB_LED_CONTROL);

RfidModule rfidModule(RFID_MODULE_SS_SDA, RFID_MODULE_RST, userNotifier);
PlayerModule playerModule(PLAYER_MODULE_RX, PLAYER_MODULE_TX, userNotifier);

PlayerMode playerMode(buttonsHandler, rfidModule, playerModule, userNotifier, currentMode);                  
ProgrammerMode programmerMode(buttonsHandler, rfidModule, playerModule, userNotifier, currentMode);                          
MasterProgrammerMode masterProgrammerMode(buttonsHandler, rfidModule, playerModule, userNotifier, currentMode); 
                                                                       
void setup() 
{
    Serial.begin(115200);
    print("Start RFID Player...");
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
