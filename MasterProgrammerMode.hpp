#ifndef _MASTERPROGRAMMERMODE_hpp
#define _MASTERPROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class MasterProgrammerMode : public ModeBase
{
public:
    MasterProgrammerMode(SoftwareSerial& p_softwareSerial,
                         MFRC522& p_rfidModule,
                         DFRobotDFPlayerMini& p_playerModule,
                         Mode& p_currentMode)
        : ModeBase(Mode::MasterProgrammer,
                   p_softwareSerial,
                   p_rfidModule,
                   p_playerModule,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        print("Process Master Programmer");
        wait(5000);
    }

private:
    void onEntry()
    {
        print("Enter Master Programmer mode");  
    }

    void onExit()
    {
        print("Exit Master Programmer mode"); 
    }
};

#endif
