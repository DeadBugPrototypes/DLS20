//-------------------------------------------------------------------------------
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// This sketch uses Adafruit RTC library https://github.com/adafruit/RTClib
// 
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------

#include <Wire.h>
#include "RTClib.h"

#define DS1337_ADDRESS      0x68

RTC_DS1307 RTC;

void setup () {
    Wire.begin();
    RTC.begin();
    RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop () {
    for (int i=0; i<30; i++)
    {
      TurnOffAlarm();  // To turn of any alarm setting.
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }
}

void TurnOffAlarm()
{
  Wire.beginTransmission(DS1337_ADDRESS);
  Wire.write((byte) 7);
  Wire.write(0b10000000);      // Alarm 1 sekunder
  Wire.write(0b10000000);      // Alarm 1 minutter
  Wire.write(0b10000000);      // Alarm 1 timer (flagg satt)
  Wire.write(0b10000000);      // Alarm 1 dato (flagg satt)
  Wire.write(0b10000000);      // Alarm 2 minutter
  Wire.write(0b10000000);      // Alarm 2 timer (flagg satt)
  Wire.write(0b10000000);      // Alarm 2 dato (flagg satt)
  Wire.write(0b00011100);      // skru av ocillator og disable alarm 1 & 2
  Wire.write((byte) 0);        // Nullstill alt
  Wire.endTransmission();
}
