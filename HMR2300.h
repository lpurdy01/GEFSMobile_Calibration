//
//  HMR2300.h
//  
//
//  Created by lpurdy on 4/17/15.
//
//

#ifndef _HMR2300_h
#define _HMR2300_h

// make sure your device ID is 00 or this library won't work

#include "Arduino.h"

#define WRITE_ENABLE F("*00WE")

#define ASCII_ON F("*00A")

#define BINARY_ON F("*00B")

#define SET_PULSE F("*00]S")

#define RESET_PULSE F("*00]R")

#define S_R_ONN F("*00TN")

#define S_R_OFF F("*00TF")

#define GET F("*00P")

#define BAUD_9600 F("*99!BR=S")

#define BAUD_19200 F("*99!BR=F")

#define SAMPLE_RATE_100 F("*00R=100")

#define AVERAGE_READINGS_ON F("*00VN")

#define AVERAGE_READINGS_OFF F("*00VF")

#define GAUSS_SCALE_MULTIPLYER 0.66666666

#define OVERALL_SCALE_MULTIPLYER .01000




class HMR2300 {
public:
    HMR2300(HardwareSerial *ser,float x,float y,float z); //Constructor using hardware serial
    
    float x,y,z; //mag values for x,y,z
    
    int intx,inty,intz;
    
    float x_cal,y_cal,z_cal;
    
    float lastx,lasty,lastz;
    
    String lastString;
    
    String lastError;
   
    void serialFlush();
    
    boolean sendCommand(const __FlashStringHelper *cmd);
    
    boolean read_ASCI_to_lastString(void);
    
    void read_to_lastString(void);
    
    int highLowCombine(byte high, byte low);
    
    boolean read(void); //must be used with the mag in binary mode
    
    long errorCount;
    
    
    
private:
    
    HardwareSerial *magHwSerial;
    
    void common_init(void);
    
    boolean error();
    
    static float GUASSMULT;
    
    static float MULT;
    
};

#endif
