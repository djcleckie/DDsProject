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
 unsigned int messageLength; 
 unsigned int screenWidth;
 unsigned int across;
 screenWidth=tft.height();
// setup and initialise the screen
//  tft.begin();
//  tft.setRotation(1);
//  tft.fillScreen(ILI9341_RED);
//  //tft.fillRect(0, 110, 320, 95, ILI9341_RED);
//  tft.setCursor(110, 10);
//  tft.setTextColor(CYAN);    
//  tft.setTextSize(4);
//  tft.println("GM4NFI");
//  tft.setTextColor(ILI9341_GREEN);  
//  tft.setCursor(55, 60);
//  tft.setTextSize(3);
//  tft.println("DDS VFO");
//  tft.setCursor(5, 100);
//  tft.setTextSize(2);
//  tft.print("QRG = ");
//  tft.println(TargetFrequency);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 110, 320, 95, ILI9341_RED);
  tft.setCursor(110, 10);
  tft.setTextColor(ILI9341_RED);    
  tft.setTextSize(4);
  //messageLength=tftMessages[0].length();
  //across=(screenWidth-messageLength)/2;
  //tft.setCursor(10,across);
  tft.println(tftMessages[0]);
  
 //tft.println("GM4NFI");
  tft.setTextColor(ILI9341_GREEN);  
  tft.setCursor(55, 60);
  tft.setTextSize(3);
  tft.println(tftMessages[1]);
  //tft.println("DDS VFO");
} 
void DisplayFreq(unsigned long Frequency) 
{
  float DisplayFrequency;

  DisplayFrequency = (Frequency / 1000000.0); // need .0 here to force cast to float
  
  tft.setTextColor(ILI9341_WHITE,ILI9341_RED);
  tft.setTextSize(4);
  tft.setCursor(15,122);
  tft.print(DisplayFrequency,5);
  tft.print("MHz");
  tft.setCursor(30,161);
  tft.setTextColor(ILI9341_BLACK, ILI9341_RED);
  tft.setCursor(15,161);
  switch (DDSStep)
  // The ^ character marks the position on the display where a click on the Rotart Encoder increments
  {
    case 10:
      tft.print("      ^");
      break;
    case 100:
      tft.print("     ^ ");
      break;
    case 1000:  
      tft.print("    ^  "); 
      break;
    case 10000: 
      tft.print("   ^   "); 
      break;
  }
}

 
 
