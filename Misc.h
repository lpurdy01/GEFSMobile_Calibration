//
//  Misc.h
//  
//
//  Created by lpurdy on 4/23/15.
//
//

#ifndef ____Misc__
#define ____Misc__

#include "Arduino.h"

#include "HMR2300.h"

void printDouble(double val, unsigned long precision,HardwareSerial *ser);

void maginit(HMR2300 *mag,HardwareSerial *ser);

#endif /* defined(____Misc__) */
