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
          m_blue(p_bluePin),
          m_currentColor(0, 0, 0)
    {
    }

    void setColor(const Color& p_color)
    {
        m_currentColor = p_color;
        analogWrite(m_red, m_currentColor.red);
        analogWrite(m_green, m_currentColor.green);
        analogWrite(m_blue, m_currentColor.blue);        
    }

    Color getCurrentColor()
    {
        return m_currentColor;
    }

    void randomColor()
    {      
        setColor(Color(random(0, 255),
                       random(0, 255),
                       random(0, 255)));
    }

private:
    const int m_red;
    const int m_green;
    const int m_blue;

    Color m_currentColor;
};

#endif
