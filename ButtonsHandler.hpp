#ifndef _BUTTONSHANDLER_hpp
#define _BUTTONSHANDLER_hpp

#include "Globals.hpp"
#include <Bounce2.h>

class ButtonsHandler
{
public:
    ButtonsHandler(AnalogPin p_playPausePin, AnalogPin p_shufflePin, AnalogPin p_masterProgrammerPin)
    {
        configureButton(m_buttonPlayPause, p_playPausePin);
        configureButton(m_buttonShuffle, p_shufflePin);
        configureButton(m_buttonMasterProgrammer, p_masterProgrammerPin);
    }

    void update()
    {
        m_buttonPlayPause.update();
        m_buttonShuffle.update();
        m_buttonMasterProgrammer.update();
    }

    bool playPausePressed()
    {
        m_buttonPlayPause.pressed();  
    }

    bool shufflePressed()
    {
        m_buttonShuffle.pressed();
    }

    bool masterProgrammerPressed()
    {
        m_buttonMasterProgrammer.pressed();  
    }
private:
    Bounce2::Button m_buttonPlayPause;
    Bounce2::Button m_buttonShuffle;
    Bounce2::Button m_buttonMasterProgrammer;

    void configureButton(Bounce2::Button& p_button, AnalogPin p_buttonPin)
    {
        pinMode(p_buttonPin, INPUT_PULLUP);
        
        p_button.attach(p_buttonPin, INPUT_PULLUP);
        p_button.interval(DEBOUNCE_INTERVAL);
        p_button.setPressedState(LOW);  
    }
};

#endif
