//-------------------------------------------------------------------------------
// This is a test sketch for the DLS 2.0 shield
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------


#include <Wire.h>
#include <SD.h>
#include <OneWire.h>

#define DS1337_ADDRESS      0x68
#define ONE_WIRE_BUS        10
#define SD_CHIPSELECT       8
#define POWEROFF            7

String strLogline = "";

void setup()
{
	Serial.begin(9600);
        pinMode(POWEROFF, OUTPUT);
        digitalWrite(POWEROFF, HIGH);
	delay(1000);
	GetDate();
	getTemp();
        getLight();
        getVolt();
	WriteSD();
}

void loop()
{
	while (true)
	{
          SetAlarmMin(10); // Set the wakeup to 10 minutes
          digitalWrite(POWEROFF, LOW);
          delay(500);
	}

}





