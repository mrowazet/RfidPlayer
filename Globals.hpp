#ifndef _GLOBALS_hpp
#define _GLOBALS_hpp

typedef int Pin;
typedef byte AnalogPin;

enum Mode
{
    Player,
    Programmer,
    MasterProgrammer
};

struct Color
{
    Color(int p_red, int p_green, int p_blue)
        : red(p_red),
          green(p_green),
          blue(p_blue)
    {
    }
    
    int red;
    int green;
    int blue;
};

static void wait(unsigned int p_ms)
{
    delay(p_ms);
}

static void print(const String& p_msg)
{
    Serial.println(p_msg.c_str());
}

#endif
