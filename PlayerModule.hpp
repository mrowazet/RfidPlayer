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
    PlayerModule(Pin p_rx, Pin p_tx, AnalogPin p_volumeRoll, UserNotifier& p_userNotifier)
        : m_softwareSerial(p_rx, p_tx),
          m_volumeRoll(p_volumeRoll),
          m_userNotifier(p_userNotifier)
    {
        m_softwareSerial.begin(9600);
        
        if (not m_dfPlayer.begin(m_softwareSerial))
        {
            print("Unable to start DFPlayer - check connections and SD card");
            m_userNotifier.communicateError();
        }

        m_dfPlayer.EQ(DFPLAYER_EQ_MODE);
    }

    void updateVolume()
    {
        unsigned long l_currentTime = millis();

        if(l_currentTime - m_lastVolumeUpdate > VOLUME_UPDATE_INTERVAL_IN_MS)
        {
            m_lastVolumeUpdate = l_currentTime;

            int l_volumeLevel = map(analogRead(m_volumeRoll),
                                    MIN_VOLUME_LEVEL, MAX_VALUE_ON_ROLL,
                                    MIN_VOLUME_LEVEL, MAX_VOLUME_ON_DFPLAYER);

            m_dfPlayer.volume(l_volumeLevel);
        }
    }

    void play(int p_fileNumber)
    {
        m_dfPlayer.play(p_fileNumber);
    }

    void randomPlay()
    {
        m_dfPlayer.randomAll();
    }

    void pause()
    {
        m_dfPlayer.pause();
    }

    void start()
    {
        m_dfPlayer.start();
    }

private:
    const int MIN_VOLUME_LEVEL = 0;
    const int MAX_VOLUME_ON_DFPLAYER = 30;
    const int MAX_VALUE_ON_ROLL = 1023;

    SoftwareSerial m_softwareSerial;
    DFRobotDFPlayerMini m_dfPlayer;
    const AnalogPin m_volumeRoll;
    UserNotifier& m_userNotifier;
    unsigned long m_lastVolumeUpdate;
};

#endif
