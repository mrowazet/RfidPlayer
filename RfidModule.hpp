#ifndef _RFIDMODULE_hpp
#define _RFIDMODULE_hpp

#include "Globals.hpp"
#include "Config.hpp"
#include <MFRC522.h>
#include <SPI.h>
#include "UserNotifier.hpp"

class RfidModule
{
public:
    RfidModule(Pin p_sda, Pin p_rst, UserNotifier& p_userNotifier)
        : m_mfrc522(p_sda, p_rst),
          m_userNotifier(p_userNotifier),
          m_lastReadTrackNumber(NO_NEW_CARD_DETECTED)
    {
        SPI.begin();
        m_mfrc522.PCD_Init();
        initializeAuthenticationKey();
    }

    int read()
    {
        if(startCommunication())
        {
            int l_trackNumber = readFromCard();
            stopCommunication();

            return l_trackNumber;
        }

        return NO_NEW_CARD_DETECTED;
    }

    bool write(int p_number)
    {
        if(startCommunication())
        {  
            bool l_result = writeToCard(p_number);
            stopCommunication();
            return l_result;
        }

        return false;
    }

    void resetLastReadTrackNumber()
    {
        m_lastReadTrackNumber = NO_NEW_CARD_DETECTED;
    }

private:
    initializeAuthenticationKey()
    {
        const int l_keyLength = 6;
        for (byte i = 0; i < l_keyLength; i++)
        {
            m_key.keyByte[i] = 0xFF; 
        }
    }

    bool startCommunication()
    {
        if(isCardValid() and authenticate())
        {
            print("Card detected and authenticated!");
            //dumpCardDetails(); //uncomment to see more info
            return true;
        }

        return false;
    }

    bool isCardValid()
    {
        if (not m_mfrc522.PICC_IsNewCardPresent() or not m_mfrc522.PICC_ReadCardSerial())
        {
            return false;
        }

        return true;
    }

    void dumpCardDetails()
    {
        m_mfrc522.PICC_DumpDetailsToSerial(&(m_mfrc522.uid));
        m_mfrc522.PICC_DumpToSerial(&(m_mfrc522.uid));    
    }

    bool authenticate()
    {
        MFRC522::StatusCode l_status = m_mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A,
                                                                  DATA_BLOCK_NUMBER,
                                                                  &m_key,
                                                                  &(m_mfrc522.uid));
        if (l_status != MFRC522::STATUS_OK) 
        {
            print("Authentication failed:");
            print(m_mfrc522.GetStatusCodeName(l_status));
            return false;
        }

        return true;
    }

    int readFromCard()
    {
        byte l_buffer[BUFFER_SIZE_FOR_READ];

        MFRC522::StatusCode l_status = m_mfrc522.MIFARE_Read(DATA_BLOCK_NUMBER,
                                                             l_buffer,
                                                             &BUFFER_SIZE_FOR_READ);
        
        if (l_status != MFRC522::STATUS_OK)
        {
            print("Reading failed: ");
            print(m_mfrc522.GetStatusCodeName(l_status));
            return NO_NEW_CARD_DETECTED;
        }
       
        int l_trackNumber = (int)l_buffer[0];

        if(l_trackNumber == MASTER_CARD_CODE)
        {
            return MASTER_CARD_CODE;
        }

        if(isTrackNumberValid(l_trackNumber) and isNewTrackNumber(l_trackNumber))
        {
            m_lastReadTrackNumber = l_trackNumber;
            return l_trackNumber;
        }
        else
        {
            return NO_NEW_CARD_DETECTED;          
        }
    }

    bool isTrackNumberValid(int p_trackNumber)
    {
        return (p_trackNumber > 0 and p_trackNumber < MAX_NUM_OF_TRACKS);
    }

    bool isNewTrackNumber(int p_trackNumber)
    {
        return p_trackNumber != m_lastReadTrackNumber;
    }

    bool writeToCard(int p_number)
    {
        byte l_buffer[BUFFER_SIZE_FOR_WRITE];
        l_buffer[0] = p_number;
        
        MFRC522::StatusCode l_status = m_mfrc522.MIFARE_Write(DATA_BLOCK_NUMBER, 
                                                              l_buffer,
                                                              BUFFER_SIZE_FOR_WRITE);
        if (l_status != MFRC522::STATUS_OK)
        {
            print("Writing failed: ");
            print(String(m_mfrc522.GetStatusCodeName(l_status)));
            return false;
        }
        else
        {
            print("Number stored on card: " + String(p_number));
            return true;
        }
    }

    void stopCommunication()
    {
        m_mfrc522.PICC_HaltA();
        m_mfrc522.PCD_StopCrypto1();      
    }    
    
    MFRC522 m_mfrc522;
    UserNotifier& m_userNotifier;

    MFRC522::MIFARE_Key m_key;
    int m_lastReadTrackNumber;

    const byte BUFFER_SIZE_FOR_READ = 18;
    const byte BUFFER_SIZE_FOR_WRITE = 16;
};

#endif
