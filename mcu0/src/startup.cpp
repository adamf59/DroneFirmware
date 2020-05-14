/**
Drone MCU0 AVR Program
*/
#include <Arduino.h>
#include "ahrs.h"
#include "batmon.h"
#include "mcu.h"


int main(void) {
    
    init(); // run the arduino.h init function

    //setup the battery read pin



    Serial.begin(9600);
    delay(1000);
    
      if(AHRS::__init__() != 0) {
          Serial.println(F("[ FAIL ] Failure initializing AHRS"));
      }
      Serial.println(F("[  OK  ] AHRS initialization completes"));

        MCU::InitializeMotors();
    
    for (;;) {
        
        // BATTERY_MONITOR::__update__();
        // Serial.print("volts: ");
        // Serial.println(BATTERY_MONITOR::GetLatestVoltage());
        // delay(1000);
    }

    return 0;
}

