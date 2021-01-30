#ifndef _INITIALIZER_hpp
#define _INITIALIZER_hpp

#include <Arduino.h>
#include "Config.hpp"
#include "Globals.hpp"

class Initializer
{
public:
    Initializer(SoftwareSerial& p_softwareSerial,
                MFRC522& p_rfidModule,
                DFRobotDFPlayerMini& p_playerModule)
        : m_softwareSerial(p_softwareSerial),
          m_rfidModule(p_rfidModule),
          m_playerModule(p_playerModule)
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
        print("Init pins...");
    }
    
    void initButtons()
    {
        print("Init buttons...");
        
        pinMode(BUTTON_PLAY_PAUSE, INPUT_PULLUP);
        pinMode(BUTTON_SHUFFLE, INPUT_PULLUP);
        pinMode(BUTTON_MASTER_PROGRAMMER_MODE, INPUT_PULLUP);
    }

    void initModules()
    {
        print("Init modules...");
        
        m_softwareSerial.begin(9600);
        SPI.begin();
        m_rfidModule.PCD_Init();
    }

    void startDFPlayer()
    {
        print("Start DFPlayer...");
        
        if (not m_playerModule.begin(m_softwareSerial))
        {
            print("Unable to start DFPlayer:");
            print("1.Check the connections");
            print("2.Check SD card");
        }
        
        initVolumeLevel();
    }

    void initVolumeLevel()
    {
        print("Init volume level...");
    }

    SoftwareSerial& m_softwareSerial;
    MFRC522& m_rfidModule;
    DFRobotDFPlayerMini& m_playerModule;
};

#endif
