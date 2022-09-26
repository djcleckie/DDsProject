//Based Microcontroller Know How Page 27
//File DDS9850_Routines.ino
// DDS Pins
#ifndef BEENHERE
#include "DDSvfo.h"
#endif
// DDS Clock should be 125,000,000 but mine is a little low
const uint32_t DDSClock = 125000000;
                         
//uint32_t TargetFrequency = 7028000;
uint32_t TargetFrequency = 3558000;
uint8_t TargetPhase = 0;
//long vfoSteps[12];

void setup() 
{
  
  setUpVfoSteps();
  Serial.begin(9600);//was 115200
  delay(3000);
  Serial.println("Starting");
  DDSInit();
  SetFrequency(TargetFrequency, TargetPhase);
}

void loop() 
{
  // put your main code here, to run repeatedly:

}



  
