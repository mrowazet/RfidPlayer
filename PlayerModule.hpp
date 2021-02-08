#ifndef _PLAYERMODULE_hpp
#define _PLAYERMODULE_hpp

#include "Globals.hpp"
#include "Config.hpp"

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include "UserNotifier.hpp"

class PlayerModule
{
public:
    PlayerModule(Pin p_rx, Pin p_tx, UserNotifier& p_userNotifier)
        : m_softwareSerial(p_rx, p_tx),
          m_userNotifier(p_userNotifier)
    {
        m_softwareSerial.begin(9600);
        
        if (not m_dfPlayer.begin(m_softwareSerial))
        {
            print("Unable to start DFPlayer - check connections and SD card");
            m_userNotifier.communicateError();
        }

        initVolumeLevel();
    }

private:
    SoftwareSerial m_softwareSerial;
    DFRobotDFPlayerMini m_dfPlayer;
    UserNotifier& m_userNotifier;
    
    void initVolumeLevel()
    {
      
    }
};

#endif
