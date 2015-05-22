//
//  Misc.cpp
//  
//
//  Created by lpurdy on 4/23/15.
//
//

#include "Misc.h"

/*void printDouble(double val, unsigned long precision, HardwareSerial *ser){
  // prints val with number of decimal places determine by precision
  // NOTE: precision is 1 followed by the number of zeros for the desired number of decimial places
  // example: printDouble( 3.1415, 100); // prints 3.14 (two decimal places)
  if(val < 0){
    ser->print("-");
    ser->print (int(val));  //prints the int part
    ser->print("."); // print the decimal point
    unsigned int frac;
    if(val >= 0)
      frac = (val - int(val)) * precision;
    else
      frac = (int(val)- val ) * precision;
    ser->print(frac,DEC) ;
  }
  else{

    ser->print (int(val));  //prints the int part
    ser->print("."); // print the decimal point
    unsigned int frac;
    if(val >= 0)
      frac = (val - int(val)) * precision;
    else
      frac = (int(val)- val ) * precision;
    ser->print(frac,DEC) ;
  }
} */

void printDouble(double val, unsigned long precision, HardwareSerial *ser){
  // prints val with number of decimal places determine by precision
  // NOTE: precision is 1 followed by the number of zeros for the desired number of decimial places
  // example: printDouble( 3.1415, 100); // prints 3.14 (two decimal places)
  String holder = "";
  holder += String(val);
  ser->print(holder);
} 


void maginit(HMR2300 *mag,HardwareSerial *ser)
{
  mag->read_to_lastString();
  ser->println(mag->lastString);

  if(mag->sendCommand(WRITE_ENABLE)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }

  if(mag->sendCommand(BINARY_ON)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }

  if(mag->sendCommand(WRITE_ENABLE)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }

  if(mag->sendCommand(S_R_OFF)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }

  ser->println(F("Reset Pulse"));

  if(mag->sendCommand(RESET_PULSE)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  } 
  delay(500);

  ser->println(F("Set Pulse"));

  if(mag->sendCommand(SET_PULSE)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  } 
  
  delay(500);
  
  if(mag->sendCommand(WRITE_ENABLE)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }
  
  if(mag->sendCommand(SAMPLE_RATE_100)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }
  
  if(mag->sendCommand(WRITE_ENABLE)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }
  
  if(mag->sendCommand(AVERAGE_READINGS_ON)) {
    ser->println(mag->lastString);
  }
  else{
    ser->println(mag->lastError);
  }
}
