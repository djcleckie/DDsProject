#ifndef BEENHERE            // Make sure we only read header file once 
  #include "DDSvfo.h"
#endif
void TFTinit()
{
// define pins for the TFT display
  // we only need to worry about non SPI pins
  pinMode(TFT_DC, OUTPUT);  // TFT pins (plus SPI1)
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_RST, OUTPUT);
  digitalWrite(TFT_DC, LOW); // internal pull-down
  digitalWrite(TFT_CS, LOW);
  digitalWrite(TFT_RST, LOW);  
}
void TFTsetup()
{
// setup and initialise the screen
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_RED);
  //tft.fillRect(0, 110, 320, 95, ILI9341_RED);
  tft.setCursor(110, 10);
  tft.setTextColor(CYAN);    
  tft.setTextSize(4);
  tft.println("GM4NFI");
  tft.setTextColor(ILI9341_GREEN);  
  tft.setCursor(55, 60);
  tft.setTextSize(3);
  tft.println("DDS VFO");
  tft.setCursor(5, 100);
  tft.setTextSize(2);
  tft.print("QRG = ");
  tft.println(TargetFrequency);
}  
