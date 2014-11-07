//-------------------------------------------------------------------------------
// getVolt() will add the input voltage read from A3 over a 10k / 15k voltage devider
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------

void getVolt(){
  int VoltReading;
  VoltReading = analogRead(A3);
  strLogline += VoltReading;
  strLogline += ';';
}
