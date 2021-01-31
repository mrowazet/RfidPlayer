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

private:
    Buzzer m_buzzer;
    RgbLed m_rgbLed;
};

#endif
