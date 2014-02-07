//-------------------------------------------------------------------------------
// WriteSD() writes the string strLogline to the SD card.
// Using the SD library http://arduino.cc/en/Reference/SD
// Please note that chip select is set to pin 8
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------

File myFile;

void WriteSD()
{
  if (!SD.begin(SD_CHIPSELECT)) {
    Serial.println("initialization failed! (No SD card, or not correctly mounted?)");
    return;
  }
  
  myFile = SD.open("DATALOG.TXT", FILE_WRITE);
  
  if (myFile) {
    myFile.println(strLogline);
    myFile.close();
    Serial.print("Writing: ");
    Serial.println(strLogline);
  } else {
    Serial.println("Error writing to DATALOG.TXT");
  }
}

