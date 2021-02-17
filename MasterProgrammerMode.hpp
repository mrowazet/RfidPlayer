#ifndef _MASTERPROGRAMMERMODE_hpp
#define _MASTERPROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class MasterProgrammerMode : public ModeBase
{
public:
    MasterProgrammerMode(ButtonsHandler& p_buttonsHandler,
                         RfidModule& p_rfidModule,
                         PlayerModule& p_playerModule,
                         UserNotifier& p_userNotifier,
                         Mode& p_currentMode)
        : ModeBase(Mode::MasterProgrammer,
                   p_buttonsHandler,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        if(m_rfidModule.write(MASTER_CARD_CODE))
        {
            changeMode(Mode::Player);
            m_userNotifier.communicateConfirm();
        }
    }

private:
    void onEntry()
    {
        print("Enter Master Programmer mode - put card next to the sensor");
        m_userNotifier.communicateModeChanged(COLOR_ORANGE);
    }

    void handlePlayPauseButton()
    {
        m_userNotifier.communicateError();
    }
    
    void handleShuffleButton()
    {
        changeMode(Mode::Player);
    }
    
    void handleMasterProgrammerButton()
    {
        m_userNotifier.communicateError();
    }
};

#endif
