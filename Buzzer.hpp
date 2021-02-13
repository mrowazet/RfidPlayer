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
        pinMode(p_buzzerPin, OUTPUT);
    }

    void shortBeep()
    {
       tone(m_buzzer, BEEP_FREQ, SHORT_BEEP_DURATION);    
    }

    void longBeep()
    {
        tone(m_buzzer, BEEP_FREQ, LONG_BEEP_DURATION);
    }

    void errorBeep()
    {
        tone(m_buzzer, BEEP_FREQ, DOUBLE_BEEP_DURATION);
        wait(DOUBLE_BEEP_GAP);
        tone(m_buzzer, BEEP_FREQ, DOUBLE_BEEP_DURATION);
    }

    void doubleBeep()
    {
        tone(m_buzzer, ERROR_BEEP_FREQ, ERROR_BEEP_DURATION); 
    }

private:
    const Pin m_buzzer;
};

#endif
