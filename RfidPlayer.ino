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
#include "RfidModule.hpp"
#include "PlayerModule.hpp"

Mode currentMode = Mode::Player;

UserNotifier userNotifier(Buzzer(BUZZER),
                          RgbLed(RGB_LED_RED,
                                 RGB_LED_GREEN,
                                 RGB_LED_BLUE));

RfidModule rfidModule(RFID_MODULE_SS_SDA, RFID_MODULE_RST, userNotifier);
PlayerModule playerModule(PLAYER_MODULE_RX, PLAYER_MODULE_TX, userNotifier);

PlayerMode playerMode(rfidModule, 
                      playerModule,
                      userNotifier, 
                      currentMode);
                      
ProgrammerMode programmerMode(rfidModule, 
                              playerModule, 
                              userNotifier,
                              currentMode);
                              
MasterProgrammerMode masterProgrammerMode(rfidModule, 
                                          playerModule,
                                          userNotifier,
                                          currentMode); 
                                                                       
void setup() 
{
    Initializer initializer(userNotifier);                           
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
