#ifndef _HELPERFUNCTIONS_hpp
#define _HELPERFUNCTIONS_hpp

#include <Arduino.h>

void wait(unsigned int ms)
{
    delay(ms);
}

void print(const String& msg)
{
    Serial.println(msg.c_str());
}

#endif
