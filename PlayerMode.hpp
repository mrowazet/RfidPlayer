#ifndef _PLAYERMODE_hpp
#define _PLAYERMODE_hpp

#include <MFRC522.h>
#include "DFRobotDFPlayerMini.h"
#include "Globals.hpp"
#include "HelperFunctions.hpp"

class PlayerMode
{
public:
    void process()
    {
        print("Enter Player mode");
        while(currentMode == Mode::Player)
        {
            wait(5000);
            return;
        }
        print("Exit Player mode");
    }

private:
};

#endif
