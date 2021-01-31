#ifndef _RGBLED_hpp
#define _RGBLED_hpp

#include "Globals.hpp"
#include "Config.hpp"

class RgbLed
{
public:
    RgbLed(const Pin p_redPin, 
           const Pin p_greenPin, 
           const Pin p_bluePin)
        : m_red(p_redPin),
          m_green(p_greenPin),
          m_blue(p_bluePin)
    {
    }

    void setRgb(const int p_red, const int p_green, const int p_blue)
    {
        analogWrite(m_red, p_red);
        analogWrite(m_green, p_green);
        analogWrite(m_blue, p_blue);
    }

    void turnOff()
    {
        setRgb(0, 0, 0);
    }

private:
    const int m_red;
    const int m_green;
    const int m_blue;
};

#endif
