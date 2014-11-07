//-------------------------------------------------------------------------------
// This function will add the analog value of A0 
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------

void getLight(){
  int photocellReading;
  
  photocellReading = analogRead(0);
  
  strLogline += photocellReading;
  strLogline += ';';
  
}

