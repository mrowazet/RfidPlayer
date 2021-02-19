-----------------
RfidPlayer
-----------------

This project was inspired on: https://ananords.com/juuke-a-rfid-music-player-for-elderly-and-kids
Project realized on Arduino UNO but can be built on another Arduino version with enough number of pins.
Circuit made in Draw.io - https://www.diagrams.net

-----------------
Description:
-----------------

Easy to use and simple to assembly MP3 player that can be connected via AUX to external speakers.
Tracks are selected based on scanned RFID self-programmed card. MP3 files with your music are stored on MicroSD card.

-----------------
Key features:
-----------------

- Play music track specified on encoded RFID card (MIFARE 1k)
- Music can be paused/played by push button
- Random track can be played by push button
- Volume level can be adjusted by knob
- Possible to encode cards with or without computer connection
- Buzzer and RGB Led used to give feedback to user

-----------------
What to do first:
-----------------

Collect all required parts.

The most important stuff you need is:
- Arduino UNO
- RC522 -> RFID module
- DFPlayer Mini -> MP3 player
- RFID cards
- buttons
- buzzer
- RGB Led (PL9823)

Needed libraries:
Adafruit_NeoPixel
DFRobotDFPlayerMini
MFRC522
Bounce2

Some configuration details can be set based on your preferences, see file Config.hpp
Here you can change Arduino PINs setting or small things like buzzer frequency.

-----------------
How to start:
-----------------

Load code from repository to your Arduino board - the simplest way to do that is:
- download Arduino IDE from official site: https://www.arduino.cc/en/software
- download this repository to your PC
- open RfidPlayer project
- install all required libraries using manager integrated to IDE
- connect board to PC
- click Load button in IDE
- done

See connection circuit stored in this repository - circuit.jpg to find out how to connect everything together and do it.

Prepare MP3 tracks that you want to use and store them in microSD card with proper names - name must start with numbers, example:
0001_track.mp3
...
0012_track.mp3

Turn on RfidPlayer, when device is ready the LED lit green.

When RfidPlayer started for the very first time push MasterProgrammer button - LED should change color to cyan.
Now, take one of the empty cards and put it next to the RC522 module, sound is generated (double beep) and LED color is green again - your 'special card' for programming is ready to use. 
With that card you will be able to encode rest of the cards with or without computer connection.

-----------------
How to configure without PC connection:
-----------------

Scan prepared 'special card', mode is changed for programming - LED color is yellow.
Push Play/Pause button to select Automatic mode - LED color is blue.
Start scanning card one by one, track numbers will be stored on cards sequentially starting from track number 1.
Double beep sound is generated when number is written on card.
Just restart device when all cards are done.

-----------------
How to configure with PC connection:
-----------------
Connect device to PC and open serial port with bitrate 115200 - some information should be printed on the screen.
Scan prepared 'special card', mode is changed for programming - LED color is yellow.

In general - from now all informations that you need to know will be printed on the screen.

First you can choose if you want to use Automatic or Manual programming mode.

Push Play/Pause button to select Automatic mode - LED color is blue.
Push MasterProgrammer button to select Manual mode - LED color is magenta.

In Automatic mode you will be pleased to scan card one by one.
First card will be encoded with track number 1, next one with track number 2 and so on (same as in configuration without PC connection).
Double beep sound is generated when number is written on card.

In Manual mode you have to put requested number to serial console and scan card to store typed track number on it.
Double beep sound is generated when number is written on card.

Just restart device when all cards are done.

Note: Music may be muted when you try to use device when connected to the PC! Do not worry and try without PC connection.

-----------------
ENJOY!
-----------------

Connect RfidPlayer by AUX to external speakers / amplifier and scan one of the prepared card to start playing your favorite music!





