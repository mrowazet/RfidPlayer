#ifndef _INITIALIZER_hpp
#define _INITIALIZER_hpp

#include <Arduino.h>
#include "Config.hpp"
#include "Globals.hpp"
#include "UserNotifier.hpp"

class Initializer
{
public:
    Initializer(UserNotifier& p_userNotifier)
        : m_userNotifier(p_userNotifier)
    {     
        Serial.begin(115200);
        print("Start RFID Player...");

        initPins();
        initButtons();
    }

private:
    void initPins()
    {    
        pinMode(RGB_LED_RED, OUTPUT);
        pinMode(RGB_LED_GREEN, OUTPUT);
        pinMode(RGB_LED_BLUE, OUTPUT);

        pinMode(BUZZER, OUTPUT);
    }
    
    void initButtons()
    {       
        pinMode(BUTTON_PLAY_PAUSE, INPUT_PULLUP);
        pinMode(BUTTON_SHUFFLE, INPUT_PULLUP);
        pinMode(BUTTON_MASTER_PROGRAMMER_MODE, INPUT_PULLUP);
    }
    
    UserNotifier& m_userNotifier;
};

#endif
