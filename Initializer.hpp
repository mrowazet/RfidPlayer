#ifndef _INITIALIZER_hpp
#define _INITIALIZER_hpp

#include <Arduino.h>
#include "Config.hpp"
#include "Globals.hpp"
#include "HelperFunctions.hpp"

class Initializer
{
public:
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
        
        softwareSerial.begin(9600);
        SPI.begin();
        rfidModule.PCD_Init();
    }

    void startDFPlayer()
    {
        print("Start DFPlayer...");
        
        if (not playerModule.begin(softwareSerial))
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
};

#endif
