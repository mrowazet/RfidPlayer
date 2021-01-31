#ifndef _MODEBASE_hpp
#define _MODEBASE_hpp

#include "Globals.hpp"
#include <SoftwareSerial.h>
#include <MFRC522.h>
#include <DFRobotDFPlayerMini.h>
#include "UserNotifier.hpp"

class ModeBase
{
public:
    ModeBase(Mode p_ownMode,
             SoftwareSerial& p_softwareSerial,
             MFRC522& p_rfidModule,
             DFRobotDFPlayerMini& p_playerModule,
             UserNotifier& p_userNotifier,
             Mode& p_currentMode)
        : m_ownMode(p_ownMode),
          m_softwareSerial(p_softwareSerial),
          m_rfidModule(p_rfidModule),
          m_playerModule(p_playerModule),
          m_userNotifier(p_userNotifier),
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

    void handleButtons()
    {
        if(buttonPressed(BUTTON_PLAY_PAUSE))
        {
            handlePlayPauseButton();
        }

        if(buttonPressed(BUTTON_SHUFFLE))
        {
            handleShuffleButton();
        }

        if(buttonPressed(BUTTON_MASTER_PROGRAMMER_MODE))
        {
            handleMasterProgrammerButton();
        }
    }

    bool buttonPressed(const Pin p_buttonPin)
    {
        bool l_stateChanged = false;
        while (digitalRead(p_buttonPin) == LOW)
        {
            l_stateChanged = true;    
        }

        if(l_stateChanged)
        {
            wait(BUTTON_PRESSED_DELAY);    
        }
        
        return l_stateChanged;
    }
    
    virtual void process() = 0;

protected:
    virtual void onEntry() = 0;
    virtual void onExit() = 0;

    virtual void handlePlayPauseButton() = 0;
    virtual void handleShuffleButton() = 0;
    virtual void handleMasterProgrammerButton() = 0;

    Mode m_ownMode;

    SoftwareSerial& m_softwareSerial;
    MFRC522& m_rfidModule;
    DFRobotDFPlayerMini& m_playerModule;
    UserNotifier& m_userNotifier;
    Mode& m_currentMode;
};

#endif
