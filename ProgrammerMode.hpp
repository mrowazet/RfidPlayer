#ifndef _PROGRAMMERMODE_hpp
#define _PROGRAMMERMODE_hpp

#include "ModeBase.hpp"

class ProgrammerMode : public ModeBase
{
public:
    ProgrammerMode(ButtonsHandler& p_buttonsHandler,
                   RfidModule& p_rfidModule,
                   PlayerModule& p_playerModule,
                   UserNotifier& p_userNotifier,
                   Mode& p_currentMode)
        : ModeBase(Mode::Programmer,
                   p_buttonsHandler,
                   p_rfidModule,
                   p_playerModule,
                   p_userNotifier,
                   p_currentMode),
          m_selectedMode(ProgrammingMode::NOT_SELECTED)
    {
    }

    void process()
    {
        if(m_selectedMode == ProgrammingMode::AUTOMATIC)
        {
            int l_calculatedNumber = m_lastUsedNumber + 1;
            storeNumberOnCard(l_calculatedNumber);
        }

        if(m_selectedMode == ProgrammingMode::MANUAL)
        {
            int l_requestedNumber = readFromSerial();
            storeNumberOnCard(l_requestedNumber);
        }
    }

private:
    enum class ProgrammingMode
    {
        NOT_SELECTED,
        AUTOMATIC,
        MANUAL
    };

    void onEntry()
    {
        print("Enter Programmer mode");
        print("Push Play/Pause button for Automatic mode");
        print("Master Programmer button for Manual mode");
        
        m_userNotifier.communicateModeChanged(COLOR_YELLOW);
    }

    void handlePlayPauseButton()
    {
        print("Use automatic programming mode");
        m_selectedMode = ProgrammingMode::AUTOMATIC;
        m_userNotifier.communicateModeChanged(COLOR_BLUE);
    }

    void handleShuffleButton()
    {
        m_lastUsedNumber = 0;
        changeMode(Mode::Player);
    }

    void handleMasterProgrammerButton()
    {
        print("Use manual programming mode");
        m_selectedMode = ProgrammingMode::MANUAL;
        m_userNotifier.communicateModeChanged(COLOR_MAGENTA);
    }

    void storeNumberOnCard(int p_trackNumber)
    {
        print("Number to be stored on card: " + String(p_trackNumber));
        
        if(not isTrackNumberValid(p_trackNumber))
        {
            print("Invalid number!");
            m_userNotifier.communicateError();
            return;
        }

        print("Put card next to the sensor");

        unsigned long l_timestamp = millis();

        while(millis() - l_timestamp < ATTEMPT_CARD_WRITE_TIMEOUT_IN_MS)
        {
            if(m_rfidModule.write(p_trackNumber))
            {
                m_lastUsedNumber = p_trackNumber;
                m_userNotifier.communicateConfirm();
                return;
            }
        }
        
        print("Card not detected! Try again");
        m_userNotifier.communicateError();
    }

    bool isTrackNumberValid(int p_trackNumber)
    {
        return (p_trackNumber > 0 and p_trackNumber < MAX_NUM_OF_TRACKS);
    }

    int readFromSerial()
    {
        print("Type number to store on card: ");
        Serial.setTimeout(USER_INPUT_TIMEOUT_IN_MS);
        int l_number = Serial.parseInt();
       
        return l_number;
    }

    ProgrammingMode m_selectedMode;
    int m_lastUsedNumber = 0;
};

#endif
