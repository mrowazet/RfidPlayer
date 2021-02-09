#ifndef _RGBLED_hpp
#define _RGBLED_hpp

#include "Globals.hpp"
#include "Config.hpp"

class RgbLed
{
public:
    RgbLed(const Pin p_rgbLedControl) 
        : m_rgbLedControl(p_rgbLedControl),
          m_currentColor(0, 0, 0)
    {
        pinMode(p_rgbLedControl, OUTPUT);
    }

    void setColor(const Color& p_color)
    {
        m_currentColor = p_color;   
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
    const Pin m_rgbLedControl;
    Color m_currentColor;
};

#endif
