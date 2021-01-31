#ifndef _PLAYERMODE_hpp
#define _PLAYERMODE_hpp

#include "ModeBase.hpp"

class PlayerMode : public ModeBase
{
public:
    PlayerMode(SoftwareSerial& p_softwareSerial,
               MFRC522& p_rfidModule,
               DFRobotDFPlayerMini& p_playerModule,
               UserNotifier& p_userNotifier,
               Mode& p_currentMode)
        : ModeBase(Mode::Player,
                   p_softwareSerial,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        print("Process Player");
        wait(5000);
        m_currentMode = Mode::Programmer;
    }

private:
    void onEntry()
    {
        print("Enter Player mode");  
    }

    void onExit()
    {
        print("Exit Player mode"); 
    }

    void handlePlayPauseButton()
    {
        print("Handle Play/Pause button");
    }
    
    void handleShuffleButton()
    {
        print("Handle Shuffle button");
    }
    
    void handleMasterProgrammerButton()
    {
        print("Handle Master Programmer button");
    }
};

#endif
