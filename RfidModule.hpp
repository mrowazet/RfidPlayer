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
          m_userNotifier(p_userNotifier)
    {
        SPI.begin();
        m_mfrc522.PCD_Init();
    }

private:
    MFRC522 m_mfrc522;
    UserNotifier& m_userNotifier;
};

#endif
