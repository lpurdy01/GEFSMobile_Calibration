//
//  HMR2300.cpp
//  
//
//  Created by lpurdy on 4/17/15.
//
//

#include "HMR2300.h"

//constructor for Hardware serial
HMR2300::HMR2300(HardwareSerial *ser,float x,float y,float z) {
    common_init();  // Set everything to common state, then...
    magHwSerial = ser; // set magHwSerial to serial given
    
    x_cal = x;
    y_cal = y;
    z_cal = z;
}

float HMR2300::GUASSMULT = GAUSS_SCALE_MULTIPLYER;
    
float HMR2300::MULT = OVERALL_SCALE_MULTIPLYER;

void HMR2300::common_init(void)
{
    magHwSerial = NULL;
  
    x = y = z = 0;
    
    errorCount = 0;
    
    lastx = lasty = lastz = 1;
    
    x_cal = y_cal = z_cal = 0;
    
}

boolean HMR2300::sendCommand(const __FlashStringHelper *cmd)
{
  serialFlush();
  magHwSerial->println(cmd);
    
  delay(60);
    
  if(magHwSerial->available() > 0){
    lastString = magHwSerial->readString();
    return true;
  }
  else{return false; errorCount++; lastError = "No response from command";}
}

void HMR2300::read_to_lastString(void)
{
  if(magHwSerial->available() > 0){
    lastString = magHwSerial->readString();
  }
}

boolean HMR2300::read_ASCI_to_lastString(void)
{
  serialFlush();
  magHwSerial->println(GET);
    
  delay(40);
  if(magHwSerial->available() > 0){
    lastString = magHwSerial->readString();
    return true;
  }
  else{return false; errorCount++; lastError = "No response from command";}
}

int HMR2300::highLowCombine(byte high, byte low)
{
  int combined;
  combined = high;
  combined = combined*256; 
  combined |= low;
  return combined;
}

boolean HMR2300::read(void)
{
  serialFlush();
  magHwSerial->println(GET);
  byte Xh;
  byte Xl;
  byte Yh;
  byte Yl;
  byte Zh;
  byte Zl;
  byte CR;
  delay(15);
  
  if(magHwSerial->available() > 1){
    Xh = magHwSerial->read();
    Xl = magHwSerial->read();
    Yh = magHwSerial->read();
    Yl = magHwSerial->read();
    Zh = magHwSerial->read();
    Zl = magHwSerial->read();
    CR = magHwSerial->read();
  }
  else{return false; errorCount++; lastError = "msg not recieved";}
  
  if(CR == 0x0D){
    intx = highLowCombine(Xh,Xl);
    inty = highLowCombine(Yh,Yl);
    intz = highLowCombine(Zh,Zl);
    
    x = -1*(((intx*GUASSMULT)*MULT) + x_cal);
    y = -1*(((inty*GUASSMULT)*MULT) + y_cal);
    z = -1*(((intz*GUASSMULT)*MULT) + z_cal);
    
    
    
    
    if(x==0){return false; errorCount++; lastError = "x=0";}
    if(y==0){return false; errorCount++; lastError = "y=0";}
    if(z==0){return false; errorCount++; lastError = "z=0";}
    /*
    if(x=lastx){return false; errorCount++; lastError = F("x=lastx");}
    if(y=lasty){return false; errorCount++; lastError = F("y=lasty");}
    if(z=lastz){return false; errorCount++; lastError = F("z=lastz");}
    
    lastx = x;
    lasty = y;
    lastz = z;
    */
    return true;
  }
  else
  {
    return false;
    errorCount++;
    lastError = "the last byte wasn't 0x0D";
  }
}

void HMR2300::serialFlush(){
  while(magHwSerial->available() > 0) {
    char t = magHwSerial->read();
  }
}
