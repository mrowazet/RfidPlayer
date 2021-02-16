###########
DRAFT
###########

RfidPlayer

This project was inspired on: https://ananords.com/juuke-a-rfid-music-player-for-elderly-and-kids
Project realized on Arduino UNO but can be built on another Arduino version with enough number of pins.
Circuit made in Draw.io - https://www.diagrams.net

Description:
Easy to use and simple to assembly MP3 player that can be connected via AUX to external speakers.
Tracks are selected based on scanned RFID self-programmed card. Files with your music are stored on MicroSD card.

Key features:
- Play music track specified on encoded RFID card (MIFARE)
- Music can be paused/played by push button
- Random track can be played by push button
- Volume level can be adjusted by knob
- Possible to encode cards with or without computer connection
- Buzzer and RGB Led used to give feedback to user

What to do first:
Collect all required parts.

The most important stuff you need is:
- Arduino UNO
- RC522 -> RFID module
- DFPlayer Mini -> MP3 player
- RFID cards
- buttons
- buzzer
- RGB Led (PL9823)

Download needed libraries:
Adafruit_NeoPixel
DFRobotDFPlayerMini
MFRC522
Bounce2

Tips:
See connection circuit stored in this repository - circuit.jpg

Some configuration details can be set based on your preferences, see file Config.hpp
Here you can change Arduino PINs setting or small things like buzzer frequency.

How to start:

How to configure without PC connection:

How to configure with PC connection: