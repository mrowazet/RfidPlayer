#ifndef _MODEBASE_hpp
#define _MODEBASE_hpp

#include "Globals.hpp"
#include "RfidModule.hpp"
#include "PlayerModule.hpp"
#include "UserNotifier.hpp"

class ModeBase
{
public:
    ModeBase(Mode p_ownMode,
             RfidModule& p_rfidModule,
             PlayerModule& p_playerModule,
             UserNotifier& p_userNotifier,
             Mode& p_currentMode)
        : m_ownMode(p_ownMode),
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
            handleButtons();
            process(); 
        }
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
        //TODO use Bounce2
        bool l_stateChanged = false;
        while (digitalRead(p_buttonPin) == LOW)
        {
            l_stateChanged = true;    
        }

        if(l_stateChanged)
        {
            String l_msg = "Button pressed: ";

            switch(p_buttonPin)
            {
                case BUTTON_PLAY_PAUSE: l_msg += "Play/Pause"; break;
                case BUTTON_SHUFFLE: l_msg += "Shuffle"; break;
                case BUTTON_MASTER_PROGRAMMER_MODE: "Master Programmer"; break;
            }
            
            print(l_msg);           
            wait(BUTTON_PRESSED_DELAY);    
        }
        
        return l_stateChanged;
    }
    
    virtual void process() = 0;

protected:
    virtual void onEntry() = 0;

    virtual void handlePlayPauseButton() = 0;
    virtual void handleShuffleButton() = 0;
    virtual void handleMasterProgrammerButton() = 0;

    void changeMode(Mode p_mode)
    {
        m_currentMode = p_mode;
    }

    Mode m_ownMode;

    RfidModule& m_rfidModule;
    PlayerModule& m_playerModule;
    UserNotifier& m_userNotifier;
    Mode& m_currentMode;
};

#endif
