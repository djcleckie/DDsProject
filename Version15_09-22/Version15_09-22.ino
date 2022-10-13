//Based Microcontroller Know How Page 27
//File DDS9850_Routines.ino
// DDS Pins
#ifndef BEENHERE
#include "DDSvfo.h"
#endif
// DDS Clock should be 125,000,000 but mine is a little low
const uint32_t DDSClock = 125000000;
// Use hardware SPI1
//tft =  Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST); // Use hardware SPI 
//uint32_t TargetFrequency = 7028000;
//uint32_t TargetFrequency = 3558000;
uint32_t TargetFrequency =  21058000;
uint8_t TargetPhase = 0;
// variables for the encoder routines
int BtnPress = LOW;
int LastBtnPress = LOW;
unsigned long lastDebounceTime = 0;  // the last time the encoder button was toggled
unsigned long debounceDelay = 180;   // the debounce time; increase if the output flickers
unsigned long DDSStep = 100;
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev;
unsigned int prevNextCode = 0;
unsigned long store=0;
char *tftMessages[]={"GM4NFI","DDS VFO","QRG"};

// constants for the upper and lower limits of the VFO
//const unsigned long VFOUpperLimit = 3800000;
const unsigned long VFOLowerLimit = 3500000;
int cnt_step = 0;
int cnt_step_old = 0;
//unsigned long TargetFrequency = 0;
//const unsigned long TargetPhase = 0;
unsigned long TargetFrequency_old = 0;

//long vfoSteps[12];

void setup() 
{
  TFTinit();
  TFTsetup();
  setupTFTmessages();
  setUpVfoSteps();
  Serial.begin(9600);//was 115200
  delay(3000);
  Serial.println("Starting Now");
  Serial.print("TargetFrequency      ");
  Serial.println(TargetFrequency); 
  DDSInit();
  SetFrequency(TargetFrequency, TargetPhase);
}

void loop() 
{
  // put your main code here, to run repeatedly:
// check for button press
  StepSelect();
  if (cnt_step != cnt_step_old) 
  {
    // if its changed we need to update the old
    // value and update the display
    cnt_step_old = cnt_step;
    DisplayFreq(TargetFrequency);
  }

  // check for tuning change
  rotary_enc();
  if (TargetFrequency != TargetFrequency_old) {
    TargetFrequency_old = TargetFrequency;
    // set DDS frequency if its changed
    // and update the display
    SetFrequency(TargetFrequency, TargetPhase);
    DisplayFreq(TargetFrequency);
  }
}

void setupTFTmessages()
 {
  tftMessages[0]="GM4NFI/P";
 }

  
