#ifndef _PLAYERMODE_hpp
#define _PLAYERMODE_hpp

#include "ModeBase.hpp"

class PlayerMode : public ModeBase
{
public:
    PlayerMode(SoftwareSerial& p_softwareSerial,
               MFRC522& p_rfidModule,
               DFRobotDFPlayerMini& p_playerModule,
               UserNotifier& p_userNotifier,
               Mode& p_currentMode)
        : ModeBase(Mode::Player,
                   p_softwareSerial,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        //TODO read cards here
        //if Master card scanned then change mode to Programmer
    }

private:
    void onEntry()
    {
        print("Enter Player mode - use card to play");
        m_userNotifier.communicateModeChanged(COLOR_GREEN);
    }

    void handlePlayPauseButton()
    {
        //TODO
    }
    
    void handleShuffleButton()
    {
        //TODO
    }
    
    void handleMasterProgrammerButton()
    {
        changeMode(Mode::MasterProgrammer);
    }

    bool m_isPlaying = false;
};

#endif
