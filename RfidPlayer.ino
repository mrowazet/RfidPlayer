#include <Arduino.h>
#include "Initializer.hpp"
#include "Globals.hpp"
#include "PlayerMode.hpp"
#include "ProgrammerMode.hpp"

PlayerMode playerMode;
ProgrammerMode programmerMode;

void setup() 
{
    Initializer initializer;
    initializer.init();
}

void loop() 
{
    if(currentMode == Mode::Player)
    {
        playerMode.process();
    }
    else
    {
        programmerMode.process();  
    }
    currentMode = Mode::Programmer;
}
