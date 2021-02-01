#ifndef _INITIALIZER_hpp
#define _INITIALIZER_hpp

#include <Arduino.h>
#include "Config.hpp"
#include "Globals.hpp"

#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <DFRobotDFPlayerMini.h>
#include "UserNotifier.hpp"

class Initializer
{
public:
    Initializer(SoftwareSerial& p_softwareSerial,
                MFRC522& p_rfidModule,
                DFRobotDFPlayerMini& p_playerModule,
                UserNotifier& p_userNotifier)
        : m_softwareSerial(p_softwareSerial),
          m_rfidModule(p_rfidModule),
          m_playerModule(p_playerModule),
          m_userNotifier(p_userNotifier)
    {     
    }
    
    void init()
    {
        Serial.begin(115200);
        print("Start RFID Player...");

        initPins();
        initButtons();
        initModules();
        startDFPlayer();

        print("Initialization complete - use card to play song");
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

    void initModules()
    {
        m_softwareSerial.begin(9600);
        SPI.begin();
        m_rfidModule.PCD_Init();
    }

    void startDFPlayer()
    {
        if (not m_playerModule.begin(m_softwareSerial))
        {
            print("Unable to start DFPlayer - check connections and SD card");
            m_userNotifier.communicateError();
        }
        
        initVolumeLevel();
    }

    void initVolumeLevel()
    {
    }

    SoftwareSerial& m_softwareSerial;
    MFRC522& m_rfidModule;
    DFRobotDFPlayerMini& m_playerModule;
    UserNotifier& m_userNotifier;
};

#endif
