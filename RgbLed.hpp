#ifndef _RGBLED_hpp
#define _RGBLED_hpp

#include <Adafruit_NeoPixel.h>
#include "Globals.hpp"
#include "Config.hpp"

class RgbLed
{
public:
    RgbLed(const Pin p_rgbLedsControl) 
        : m_currentColor(0, 0, 0)
    {
        pinMode(p_rgbLedsControl, OUTPUT);

        m_leds = new Adafruit_NeoPixel(NUM_OF_RGB_LEDS, 
                                       p_rgbLedsControl, 
                                       NEO_RGB + NEO_KHZ800);
    }

    ~RgbLed()
    {
        delete m_leds;
    }

    void setColor(const Color& p_color)
    {
        m_currentColor = p_color;
        
        for(int i = 0; i < NUM_OF_RGB_LEDS; i++)
        {
            m_leds->setPixelColor(i, m_leds->Color(m_currentColor.red, 
                                                   m_currentColor.green, 
                                                   m_currentColor.blue));  
        }

        m_leds->show();
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

    void turnOff()
    {
        m_leds->clear();
        m_leds->show();
    }

private:
    Adafruit_NeoPixel* m_leds;
    Color m_currentColor;
};

#endif
