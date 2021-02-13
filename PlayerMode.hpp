#ifndef _PLAYERMODE_hpp
#define _PLAYERMODE_hpp

#include "ModeBase.hpp"

class PlayerMode : public ModeBase
{
public:
    PlayerMode(ButtonsHandler& p_buttonsHandler,
               RfidModule& p_rfidModule,
               PlayerModule& p_playerModule,
               UserNotifier& p_userNotifier,
               Mode& p_currentMode)
        : ModeBase(Mode::Player,
                   p_buttonsHandler,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode)
    {     
    }
    
    void process()
    {
        int l_detectedNumber = m_rfidModule.read();
        
        if(l_detectedNumber == NO_NEW_CARD_DETECTED)
        {
            return;
        }

        if(l_detectedNumber == MASTER_CARD_CODE)
        {
            pausePlaying();
            changeMode(Mode::Programmer);
            return;
        }

        pausePlaying();
        m_userNotifier.communicateCardRead();
        startPlaying(l_detectedNumber);
    }

private:
    void onEntry()
    {
        print("Enter Player mode - use card to play");
        m_userNotifier.communicateModeChanged(COLOR_GREEN);
    }

    void handlePlayPauseButton()
    {
        if(isPlaying())
        {
            pausePlaying(); 
        }
        else
        {
            resumePlaying();
        }
    }
    
    void handleShuffleButton()
    {
        m_isPlaying = true;
        m_playerModule.randomPlay();
    }
    
    void handleMasterProgrammerButton()
    {
        pausePlaying();
        changeMode(Mode::MasterProgrammer);
    }

    void startPlaying(int p_fileNumber)
    {
        m_isPlaying = true;
        m_playerModule.play(p_fileNumber); 
    }

    void pausePlaying()
    {
        m_isPlaying = false;
        m_playerModule.pause();  
    }

    void resumePlaying()
    {
        m_isPlaying = true;
        m_playerModule.start();
    }

    bool isPlaying() const
    {
        return m_isPlaying;
    }
    
    bool m_isPlaying = false;
};

#endif
