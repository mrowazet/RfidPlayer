#ifndef _MODEBASE_hpp
#define _MODEBASE_hpp

#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <DFRobotDFPlayerMini.h>
#include "Globals.hpp"

class ModeBase
{
public:
    ModeBase(Mode p_ownMode,
             SoftwareSerial& p_softwareSerial,
             MFRC522& p_rfidModule,
             DFRobotDFPlayerMini& p_playerModule,
             Mode& p_currentMode)
        : m_ownMode(p_ownMode),
          m_softwareSerial(p_softwareSerial),
          m_rfidModule(p_rfidModule),
          m_playerModule(p_playerModule),
          m_currentMode(p_currentMode)
    {     
    }

    void startProcessing()
    {
        onEntry();
        
        while(m_currentMode == m_ownMode)
        {
            process(); 
        }
        
        onExit();
    }
    virtual void process() = 0;

protected:
    virtual void onEntry() = 0;
    virtual void onExit() = 0;

    Mode m_ownMode;

    SoftwareSerial& m_softwareSerial;
    MFRC522& m_rfidModule;
    DFRobotDFPlayerMini& m_playerModule;
    Mode& m_currentMode;
};

#endif
