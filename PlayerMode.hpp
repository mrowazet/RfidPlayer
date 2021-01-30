#ifndef _PLAYERMODE_hpp
#define _PLAYERMODE_hpp

#include <MFRC522.h>
#include "DFRobotDFPlayerMini.h"
#include "Globals.hpp"

class PlayerMode
{
public:
    PlayerMode(SoftwareSerial& p_softwareSerial,
               MFRC522& p_rfidModule,
               DFRobotDFPlayerMini& p_playerModule,
               Mode& p_currentMode)
        : m_softwareSerial(p_softwareSerial),
          m_rfidModule(p_rfidModule),
          m_playerModule(p_playerModule),
          m_currentMode(p_currentMode)
    {     
    }
    
    void process()
    {
        print("Enter Player mode");
        while(m_currentMode == Mode::Player)
        {
            wait(5000);
            return;
        }
        print("Exit Player mode");
    }

private:
    SoftwareSerial& m_softwareSerial;
    MFRC522& m_rfidModule;
    DFRobotDFPlayerMini& m_playerModule;
    Mode& m_currentMode;
};

#endif
