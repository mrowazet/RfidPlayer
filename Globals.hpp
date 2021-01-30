#ifndef _GLOBALS_hpp
#define _GLOBALS_hpp

enum Mode
{
    Player,
    Programmer,
    MasterProgrammer
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
