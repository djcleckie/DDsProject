#ifndef BEENHERE            // Make sure we only read header file once 
  #define BEENHERE
//################## AD9850 Pins #####################   
  #define DDSRST PB8
  #define DATA PB7
  #define FQ_UD   PB9
  #define CLOCK  PB6
  //################## Stepper Pins  ##################### 
  #define microPin1       PA9  //M0 or MS1 Red wire                                                                             
  #define microPin2       PA10  //was 6 White wire
  #define microPin3       PA11  //was 7 Yellow Wire
  #define enablePin          PA12  //DRV8825 stepPin black wire. Low is enable 
  #define dirPin             PA15  // DRV8825 dirPin  Purple
  #define stepPin            PB3   // DRV8825 stepPin  Blue
//################## includes #####################   
  #include <Arduino.h>
  //##################function prototypes #####################  
  void DDSInit(void);
  void pulseHigh(int );  
  void TransferByte(byte ); 
  void SetFrequency (uint32_t, uint8_t) ; 
  void UpdateDDS(int32_t, uint8_t);  
  void DDSDown(void);
  void setUpVfoSteps(void);  
  //  ################ Extern variables and constants ##############
  extern const uint32_t DDSClock;
  extern long vfoSteps[];
  // ################ Color definitions ################
  #define BLACK         0x0000
  #define BLUE          0x001F
  #define RED           0xF800
  #define GREEN         0x07E0
  #define CYAN          0x07FF
  #define MAGENTA       0xF81F
  #define YELLOW        0xFFE0
  #define WHITE         0xFFFF
  #define DKGREEN       0x03E0  
#endif