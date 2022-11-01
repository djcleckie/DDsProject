#ifndef BEENHERE            // Make sure we only read header file once 
  #include "DDSvfo.h"
#endif


// Rotary Encoder routines

// this only returns when the bit pattern is as expected
// it debounces the rotary encoder well
// A vald CW or  CCW move returns 1 or -1, invalid returns 0
unsigned int read_rotary() 
{
  static unsigned int rot_enc_table[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};

  prevNextCode <<= 2;
  if (digitalRead(pin_A)) prevNextCode |= 0x02;
  if (digitalRead(pin_B)) prevNextCode |= 0x01;
  prevNextCode &= 0x0f;

   // If valid then store as 16 bit data.
   if  (rot_enc_table[prevNextCode] ) {
      store <<= 4;
      store |= prevNextCode;

      if ((store&0xff)==0x2b) return -1;
      if ((store&0xff)==0x17) return 1;
   }
   return 0;
}

void rotary_enc()
{

  static unsigned int val;

  if( val=read_rotary() ) 
  {
    if ( prevNextCode==0x0b) 
    {
      TargetFrequency = TargetFrequency + DDSStep;
      if (TargetFrequency < VFOLowerLimit) 
      {
        TargetFrequency = VFOUpperLimit;
      }
    }
    if ( prevNextCode==0x07) 
    {
      TargetFrequency = TargetFrequency - DDSStep;
      if (TargetFrequency > VFOUpperLimit) 
      {
        TargetFrequency = VFOLowerLimit;
      }
    }
  }
}

void StepSelect()
{
  BtnPress = digitalRead(BTN);

  if (BtnPress != LastBtnPress)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (BtnPress == LOW)
    {
      if (cnt_step == 0) {
        DDSStep = 10; 
      }
      else if (cnt_step == 1) {
        DDSStep = 100; 
      }
      else if (cnt_step == 2) {
        DDSStep = 1000;  
      }
      else if (cnt_step == 3) {
        DDSStep = 10000;  
      }
      cnt_step = cnt_step + 1;
    
      if (cnt_step == 4) {
        cnt_step = 0 ;
      }
    }
  }  
  LastBtnPress = BtnPress;
}//end StepSelect()
