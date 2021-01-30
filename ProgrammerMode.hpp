#ifndef _PROGRAMMERMODE_hpp
#define _PROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class ProgrammerMode : public ModeBase
{
public:
    ProgrammerMode(SoftwareSerial& p_softwareSerial,
                   MFRC522& p_rfidModule,
                   DFRobotDFPlayerMini& p_playerModule,
                   Mode& p_currentMode)
        : ModeBase(Mode::Programmer,
                   p_softwareSerial,
                   p_rfidModule,
                   p_playerModule,
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
};

#endif
