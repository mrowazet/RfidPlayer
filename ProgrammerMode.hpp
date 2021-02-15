#ifndef _PROGRAMMERMODE_hpp
#define _PROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class ProgrammerMode : public ModeBase
{
public:
    ProgrammerMode(ButtonsHandler& p_buttonsHandler,
                   RfidModule& p_rfidModule,
                   PlayerModule& p_playerModule,
                   UserNotifier& p_userNotifier,
                   Mode& p_currentMode)
        : ModeBase(Mode::Programmer,
                   p_buttonsHandler,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {

    }

private:
    void onEntry()
    {
        print("Enter Programmer mode");
        m_userNotifier.communicateModeChanged(COLOR_YELLOW);  
    }
    
    void handlePlayPauseButton()
    {
        print("Use automatic programming mode");
        m_userNotifier.communicateModeChanged(COLOR_BLUE);
    }
    
    void handleShuffleButton()
    {
        changeMode(Mode::Player);
    }
    
    void handleMasterProgrammerButton()
    {
        print("Use manual programming mode");
        m_userNotifier.communicateModeChanged(COLOR_MAGENTA);
    }
};

#endif
