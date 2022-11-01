#ifndef BEENHERE            // Make sure we only read header file once 
  #include "DDSvfo.h"
#endif
long vfoSteps[12];
void DDSInit()
{
  pinMode (DATA, OUTPUT);   // DDS pins as output
  pinMode (CLOCK, OUTPUT);  
  pinMode (FQ_UD, OUTPUT);   
  pinMode (DDSRST, OUTPUT);
  digitalWrite(DATA, LOW);  // internal pull-down
  digitalWrite(CLOCK, LOW);
  digitalWrite(FQ_UD, LOW);
  digitalWrite(DDSRST, LOW);
    
  // give the AD9851 2 seconds after power on
  delay (1000);
  pulseHigh(DDSRST);
  pulseHigh(CLOCK);
  pulseHigh(FQ_UD);  // this pulse enables serial mode on the AD9850 - Datasheet page 12.  

  
}
void pulseHigh(int pin)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(2);
  digitalWrite(pin, LOW);
}
void TransferByte(byte data)
{
  for (int i=0; i<8; i++, data>>=1) 
  {
    digitalWrite(DATA, data & 0x01);
    pulseHigh(CLOCK);   //after each bit sent, CLK is pulsed high
  }
}
void SetFrequency (uint32_t TargetFrequency, uint8_t TargetPhase)
//TargetFrequency = 7028000;
{
  int32_t freq = TargetFrequency * 4294967296/DDSClock;
  uint8_t phase = TargetPhase << 3;
  Serial.print("Sending Freq: ");
  Serial.print(freq);
  Serial.print(" Phase: ");
  Serial.println(phase);
  UpdateDDS (freq, phase);  
}
void UpdateDDS(int32_t freq, uint8_t Phase)
{
  for (int b=0; b<4; b++, freq>>=8) 
  {
    Serial.print("Sending ");
    Serial.println(freq & 0xFF, HEX);
    TransferByte(freq & 0xFF);
  }
  Serial.print("Sending ");
  Serial.println(Phase, HEX);
  TransferByte (Phase & 0xFF);
  pulseHigh(FQ_UD);
}
void DDSDown()
{
  pulseHigh(FQ_UD);
  TransferByte(0x04);
  pulseHigh(FQ_UD);
}
void setUpVfoSteps()
{
  vfoSteps[0]=10L;//10Hz
  vfoSteps[1]=100L;//100Hz
  vfoSteps[2]=500L;//500Hz
  vfoSteps[3]=1000L;//1KHz
  vfoSteps[4]=5000L;//5KHz
  vfoSteps[5]=10000L;//10kHz
  vfoSteps[6]=50000L;//50kHz
  vfoSteps[7]=100000L;//100Kz
  vfoSteps[8]=500000L;//500KHz
  vfoSteps[9]=1000000L;//1Mhz
  vfoSteps[10]=5000000L;//5MHz
  vfoSteps[11]=10000000L;//10MHz
}
