/**
  @file    ads7843_eg.ino
  @author  www.elechouse.com
  @brief   example of ELECHOUSE ads7843 library
  
  @section  HISTORY
  
  V1.0 initial version
  
    Copyright (c) 2013 www.elechouse.com  All right reserved.
*/
#include <ads7843.h>

#ifdef ELECFREAKS_TFT_SHIELD_V2
#define DCLK     6
#define CS       5  
#define DIN      4 
#define DOUT     3
#define IRQ      2 
#else
/** Elechouse TFT shield pin map */
#define DCLK     25
#define CS       26 
#define DIN      27 
#define DOUT     29
#define IRQ      30
#endif 

ADS7843 touch(CS, DCLK, DIN, DOUT, IRQ);
Point p;

void setup(void)
{
  Serial.begin(115200);
  touch.begin();
}

void loop(void)
{
  uint8_t flag;
  /** getpos */
  p=touch.getpos(&flag) ;
  if(flag){
    /** get position successfully */
    
    /** print the coordinate */
    Serial.print(p.x, DEC);
    Serial.print("   ");
    Serial.print(p.y, DEC);
    Serial.println();
  }
}
