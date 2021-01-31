#ifndef _BUZZER_hpp
#define _BUZZER_hpp

#include "Globals.hpp"
#include "Config.hpp"

class Buzzer
{
public:
    Buzzer(const Pin p_buzzerPin)
        : m_buzzer(p_buzzerPin)
    {
    }

private:
    const int m_buzzer;
};

#endif
