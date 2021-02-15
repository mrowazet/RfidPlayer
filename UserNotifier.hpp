#ifndef _USERNOTIFIER_hpp
#define _USERNOTIFIER_hpp

#include "Globals.hpp"
#include "Config.hpp"
#include "Buzzer.hpp"
#include "RgbLed.hpp"

class UserNotifier
{
public:
    UserNotifier(Pin p_buzzer, Pin p_rgbLed)
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
        m_buzzer.confirmBeep();
        wait(CONFIRM_BEEP_WITH_OFFSET);
    }

    void communicateCardRead()
    {
        m_rgbLed.randomColor();
        m_buzzer.shortBeep();
        
        //tone() function will interfere with PWM output on pins 3 and 11 (MOSI) so wait to avoid problems
        wait(CARD_READ_BEEP_WITH_OFFSET); 
    }

    void communicateError()
    {
        print("Error - unexpected event");
        Color l_colorBeforeError = m_rgbLed.getCurrentColor();
        
        m_rgbLed.setColor(COLOR_RED);
        m_buzzer.errorBeep();
        wait(ERROR_BEEP_DURATION);

        m_rgbLed.setColor(l_colorBeforeError);
    }

private:
    Buzzer m_buzzer;
    RgbLed m_rgbLed;
};

#endif
