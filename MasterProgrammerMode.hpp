#ifndef _MASTERPROGRAMMERMODE_hpp
#define _MASTERPROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class MasterProgrammerMode : public ModeBase
{
public:
    MasterProgrammerMode(RfidModule& p_rfidModule,
                         PlayerModule& p_playerModule,
                         UserNotifier& p_userNotifier,
                         Mode& p_currentMode)
        : ModeBase(Mode::MasterProgrammer,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        //TODO write master code to card here and go back to player mode
    }

private:
    void onEntry()
    {
        print("Enter Master Programmer mode - put card next to the sensor");
        m_userNotifier.communicateModeChanged(COLOR_ORANGE);
    }

    void handlePlayPauseButton()
    {
        //unused
        m_userNotifier.communicateError();
    }
    
    void handleShuffleButton()
    {
        changeMode(Mode::Player);
    }
    
    void handleMasterProgrammerButton()
    {
        //unused
        m_userNotifier.communicateError();
    }
};

#endif
