#ifndef _PROGRAMMERMODE_hpp
#define _PROGRAMMERMODE_hpp

#include <MFRC522.h>
#include "DFRobotDFPlayerMini.h"
#include "Globals.hpp"

class ProgrammerMode
{
public:
    ProgrammerMode(SoftwareSerial& p_softwareSerial,
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
        print("Enter Programmer mode");
        while(m_currentMode == Mode::Programmer)
        {
            wait(5000);
            return;
        }
        print("Exit Programmer mode");    
    }

private:
    SoftwareSerial& m_softwareSerial;
    MFRC522& m_rfidModule;
    DFRobotDFPlayerMini& m_playerModule;
    Mode& m_currentMode;
};

#endif
