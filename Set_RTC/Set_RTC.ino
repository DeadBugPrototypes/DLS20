//-------------------------------------------------------------------------------
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
// This sketch uses Adafruit RTC library https://github.com/adafruit/RTClib
// 
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

void setup () {
    Wire.begin();
    RTC.begin();
    RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop () {
    for (int i=0; i<30; i++)
    {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }
}
