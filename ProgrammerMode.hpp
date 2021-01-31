#ifndef _PROGRAMMERMODE_hpp
#define _PROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class ProgrammerMode : public ModeBase
{
public:
    ProgrammerMode(SoftwareSerial& p_softwareSerial,
                   MFRC522& p_rfidModule,
                   DFRobotDFPlayerMini& p_playerModule,
                   UserNotifier& p_userNotifier,
                   Mode& p_currentMode)
        : ModeBase(Mode::Programmer,
                   p_softwareSerial,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        print("Process Programmer");
        wait(5000);
    }

private:
    void onEntry()
    {
        print("Enter Programmer mode");  
    }

    void onExit()
    {
        print("Exit Programmer mode"); 
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
