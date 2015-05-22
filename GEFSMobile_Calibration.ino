//Main INO file

#include "HMR2300.h"
#include "MemoryFree.h"
#include "Misc.h"
#include "config.h"

HardwareSerial compSerial = Serial; //Main Serial port

HardwareSerial mySerial = Serial1; //magnetometer

HMR2300 mag(&mySerial, 41.21, 30.36, -25.32); //magnetometer initialize

// Interval is how long we wait
const int intervalMAG = intervalMagnetometer;
// Tracks the time since last event fired
unsigned long previousMillisMAG = 0;

float x_min,x_max;
float y_min,y_max;
float z_min,z_max;

void setup()
{
  Serial.begin(115200);

  Serial1.begin(9600);

  delay(100);

  maginit(&mag, &compSerial);

  delay(1000); // Give the magnetometer time to relax
  
  x_min = 100;
  y_min = 100;
  z_min = 100;
  
  x_max = -100;
  y_max = -100;
  z_max = -100;

}
void loop()
{
  unsigned long currentMillis = millis();

  if ((unsigned long)(currentMillis - previousMillisMAG) >= intervalMAG) {

    if (mag.read()) {// If we get a set of values from the magnetometer
      previousMillisMAG = currentMillis; //Reset the timer Do Printy stuff
      /*printDouble(mag.intx,10000000, &compSerial);
       Serial.print(F(","));
       printDouble(mag.inty,10000000, &compSerial);
       Serial.print(F(","));
       printDouble(mag.intz,10000000, &compSerial);
       Serial.print("   ");*/

      printDouble(mag.x,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(mag.y,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(mag.z,10000000, &compSerial);
      Serial.print("  ");
      
      

      if(mag.x < x_min){
        x_min = mag.x;
      }
      if(mag.y < y_min){
        y_min = mag.y;
      }
      if(mag.z < z_min){
        z_min = mag.z;
      }

      if(mag.x > x_max){
        x_max = mag.x;
      }
      if(mag.y > y_max){
        y_max = mag.y;
      }
      if(mag.z > z_max){
        z_max = mag.z;
      }

      Serial.print(F("Mins: "));
      printDouble(x_min,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(y_min,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(z_min,10000000, &compSerial);
      Serial.print("  ");

      Serial.print(F("Maxs: "));
      printDouble(x_max,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(y_max,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(z_max,10000000, &compSerial);
      Serial.print("  ");
      
      float difx = (x_max - x_min);
      float dify = (y_max - y_min);
      float difz = (z_max - z_min);

      Serial.print(F("Difs: "));
      printDouble(difx,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(dify,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(difz,10000000, &compSerial);
      Serial.print("  ");
      
      float centx = x_max-(.5*difx);
      float centy = y_max-(.5*dify);
      float centz = z_max-(.5*difz);
      
      Serial.print(F("Range Center: "));
      printDouble(centx,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(centy,10000000, &compSerial);
      Serial.print(F(","));
      printDouble(centz,10000000, &compSerial);
      Serial.println("  ");
      
      


    }
    else{
      delay(50);
    }
    //***************************magnetometer timer*****************************************end
  }
}


