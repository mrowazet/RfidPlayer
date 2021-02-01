#ifndef _USERNOTIFIER_hpp
#define _USERNOTIFIER_hpp

#include "Globals.hpp"
#include "Config.hpp"
#include "Buzzer.hpp"
#include "RgbLed.hpp"

class UserNotifier
{
public:
    UserNotifier(Buzzer p_buzzer, RgbLed p_rgbLed) //intentional copy
        : m_buzzer(p_buzzer),
          m_rgbLed(p_rgbLed)
    {
    }

    void communicateModeChanged(const Color& p_color)
    {
        m_rgbLed.setColor(p_color);
        m_buzzer.longBeep();  
    }

    void communicateConfirm()
    {
        m_buzzer.doubleBeep();
    }

    void communicateCardRead()
    {
        m_rgbLed.randomColor();
        m_buzzer.shortBeep();
    }

    void communicateError()
    {
        Color l_currentColor = m_rgbLed.getCurrentColor();
        
        m_rgbLed.setColor(COLOR_RED);
        m_buzzer.errorBeep();

        m_rgbLed.setColor(l_currentColor);
    }

private:
    Buzzer m_buzzer;
    RgbLed m_rgbLed;
};

#endif
