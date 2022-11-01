#ifndef BEENHERE            // Make sure we only read header file once 
  #define BEENHERE
//################## AD9850 Pins on Separate board #####################   
//  #define DDSRST PB8
//  #define DATA PB7
//  #define FQ_UD   PB9
//  #define CLOCK  PB6
//################## AD9850 Pins Blue Pill and AD9850 same veroboard using vero strips) #####################   
   #define DDSRST PB6
   #define DATA PB7
   #define FQ_UD   PB8
   #define CLOCK  PB9
  //################## Stepper Pins  ##################### 
  #define microPin1       PA9  //M0 or MS1 Red wire                                                                             
  #define microPin2       PA10  //was 6 White wire
  #define microPin3       PA11  //was 7 Yellow Wire
  #define enablePin          PA12  //DRV8825 stepPin black wire. Low is enable 
  #define dirPin             PA15  // DRV8825 dirPin  Purple
  #define stepPin            PB3   // DRV8825 stepPin  Blue
//##################  rotary encoder pins ################## 
  #define pin_A  PB12
  #define pin_B PB13 
  #define BTN   PB14  
//################## TFT pins SPI1 plus: ################## 
//      Vcc 3.3V             --->  ILI9340 Pin# 1
//      GND                  --->          Pin# 2
// ################## User defined  TFT pins
#define TFT_CS    PA1 // --->          Pin# 3
#define TFT_RST   PA4 // --->          Pin# 4
#define TFT_DC    PA3 // --->          Pin# 5
//################## Hardware SPI TFT pins 
//      TFT_MOSI //PA7       --->          Pin# 6
//      TFT_SCK  //PA5       --->          Pin# 7
//      LED backlight  3V3   --->          Pin# 8
//      TFT_MISO       N/C  or PA6 --->          Pin# 9  
//################## includes #####################   
  #include <Arduino.h>
  #include <SPI.h>
  #include <Adafruit_GFX.h>
  #include  <Adafruit_ILI9341.h> 
  #include <HardwareSerial.h>
//################## Constants #####################
#define VFOUpperLimit  3800000
#define VFOLowerLimit  3500000
//#define cnt_step 0
//#define cnt_step_old 0
//#define TargetFrequency 0ul
//#define  TargetPhase 0ul
//#define TargetFrequency_old 0
//##################function prototypes #####################  
  void DDSInit(void);
  void TFTinit(void);
  void TFTsetup(void); 
  void pulseHigh(int );  
  void TransferByte(byte ); 
  void SetFrequency (uint32_t, uint8_t) ; 
  void UpdateDDS(int32_t, uint8_t);  
  void DDSDown(void);
  void setUpVfoSteps(void);  
  unsigned int read_rotary(void); 
  void DisplayFreq(unsigned long);
  void StepSelect();
  void rotary_enc();
  //void setupTFTmessages();
  //  ################ Extern classes, variables and constants ##############
  extern Adafruit_ILI9341  tft;
  extern const uint32_t DDSClock;
  extern long vfoSteps[];
  extern int BtnPress;
  extern int LastBtnPress;
  extern unsigned long lastDebounceTime;  // the last time the encoder button was toggled
  extern unsigned long debounceDelay;   // the debounce time; increase if the output flickers
  extern unsigned long DDSStep;
  extern unsigned char encoder_A;
  extern unsigned char encoder_B;
  extern unsigned char encoder_A_prev;
  extern unsigned int prevNextCode;
  extern  unsigned long store;
  extern const unsigned long VFOUpperLimit;
  extern const unsigned long VFOLowerLimit;
  extern int cnt_step;
  extern int cnt_step_old;
  extern uint32_t  TargetFrequency;
  extern uint8_t TargetPhase;
  extern unsigned long TargetFrequency_old; 
  extern char *tftMessages[]; 
  //extern HardwareSerial  Serial;
  
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


// ################ Class tftDisplay declaration ################  
class tftDisplay
{
private:
unsigned int m_screenWidth;
unsigned int m_screenDepth;
char *tftMessages[5]={"GM4NFI","DDS VFO","QRG"};
public:
tftDisplay()//the constructor
{}
void setScreenWidth(void);
void setScreenDepth(void);
unsigned int getScreenWidth(unsigned int);
unsigned int getScreenDepth(unsigned int);  
};
// ################ End of Class tftDisplay declaration ################  



#endif
