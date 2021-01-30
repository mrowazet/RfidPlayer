#ifndef _PROGRAMMERMODE_hpp
#define _PROGRAMMERMODE_hpp

#include <MFRC522.h>
#include "DFRobotDFPlayerMini.h"
#include "Globals.hpp"
#include "HelperFunctions.hpp"

class ProgrammerMode
{
public:
    void process()
    {
        print("Enter Programmer mode");
        while(currentMode == Mode::Programmer)
        {
            wait(5000);
            return;
        }
        print("Exit Programmer mode");    
    }

private:
  
};

#endif
