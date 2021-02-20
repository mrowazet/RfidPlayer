#ifndef _RGBLED_hpp
#define _RGBLED_hpp

#include <Adafruit_NeoPixel.h>
#include "Globals.hpp"
#include "Config.hpp"

class RgbLed
{
public:
    RgbLed(const Pin p_rgbLedsControl) 
        : m_leds(NUM_OF_RGB_LEDS, p_rgbLedsControl, NEO_RGB + NEO_KHZ800),
          m_currentColor(0, 0, 0)
    {
        m_leds.begin();
    }

    void setColor(const Color& p_color)
    {
        m_currentColor = p_color;
        
        for(int i = 0; i < NUM_OF_RGB_LEDS; i++)
        {
            m_leds.setPixelColor(i, m_leds.Color(p_color.red,
                                                 p_color.green,
                                                 p_color.blue));
            m_leds.show();
        }
    }

    Color getCurrentColor()
    {
        return m_currentColor;
    }

    void randomColor()
    {      
        m_lastColorUpdate = millis();
        setColor(shuffleIntensiveColor());
    }

    void colorUpdate()
    {
        unsigned long l_currentTime = millis();

        if(l_currentTime - m_lastColorUpdate > COLOR_UPDATE_INTERVAL_IN_MS)
        {
            m_lastColorUpdate = l_currentTime;
            setColor(shuffleIntensiveColor());
        }  
    }

private:
    Color  shuffleIntensiveColor()
    {
        Color l_color (random(0, 255),
                       random(0, 255),
                       random(0, 255));

        while(true)
        {
            if((l_color.red > MIN_VALUE_FOR_MOST_INTENSIVE_COLOR and l_color.green < MAX_VALUE_FOR_LESS_INTENSIVE_COLORS and l_color.blue < MAX_VALUE_FOR_LESS_INTENSIVE_COLORS)
                or (l_color.red < MAX_VALUE_FOR_LESS_INTENSIVE_COLORS and l_color.green > MIN_VALUE_FOR_MOST_INTENSIVE_COLOR and l_color.blue < MAX_VALUE_FOR_LESS_INTENSIVE_COLORS)
                or (l_color.red < MAX_VALUE_FOR_LESS_INTENSIVE_COLORS and l_color.green < MAX_VALUE_FOR_LESS_INTENSIVE_COLORS and l_color.blue > MIN_VALUE_FOR_MOST_INTENSIVE_COLOR))
            {
                return l_color;
            }
            else
            {
                l_color.red = random(0, 255);
                l_color.green = random(0, 255);
                l_color.blue = random(0, 255);
            }            
        }
    }

    Adafruit_NeoPixel m_leds;
    Color m_currentColor;
    unsigned long m_lastColorUpdate;
};

#endif
