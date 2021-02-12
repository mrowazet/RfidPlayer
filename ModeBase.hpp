#ifndef _MODEBASE_hpp
#define _MODEBASE_hpp

#include "Globals.hpp"
#include "ButtonsHandler.hpp"
#include "RfidModule.hpp"
#include "PlayerModule.hpp"
#include "UserNotifier.hpp"

class ModeBase
{
public:
    ModeBase(Mode p_ownMode,
             ButtonsHandler& p_buttonsHandler,
             RfidModule& p_rfidModule,
             PlayerModule& p_playerModule,
             UserNotifier& p_userNotifier,
             Mode& p_currentMode)
        : m_ownMode(p_ownMode),
          m_buttonsHandler(p_buttonsHandler),
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
        m_buttonsHandler.update();
        
        if(m_buttonsHandler.playPausePressed())
        {
            print("Play/Pause button pressed");
            handlePlayPauseButton();
        }

        if(m_buttonsHandler.shufflePressed())
        {
            print("Shuffle button pressed");
            handleShuffleButton();
        }

        if(m_buttonsHandler.masterProgrammerPressed())
        {
            print("Master Programmer button pressed");
            handleMasterProgrammerButton();
        }
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

    ButtonsHandler& m_buttonsHandler;
    RfidModule& m_rfidModule;
    PlayerModule& m_playerModule;
    UserNotifier& m_userNotifier;
    Mode& m_currentMode;
};

#endif
