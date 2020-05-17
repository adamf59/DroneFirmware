/**
Drone MCU0 AVR Program
*/
#include <Arduino.h>
#include "ahrs.h"
#include "pid_controller.h"

int main(void) {
    
    init(); // run the arduino.h init function

    //setup the battery read pin



    Serial.begin(9600);
    delay(1000);
    
      if(AHRS::__init__() != 0) {
          Serial.println(F("[ FAIL ] Failure initializing AHRS"));
      }
      Serial.println(F("[  OK  ] AHRS initialization completes"));
    
    PIDController autoRoll(-5,-0.0003,90);
    autoRoll.setTarget(0);
    for (;;) {
      long updateTime = AHRS::__update__();

      Serial.print("Roll: ");
      Serial.print(AHRS::GetRollData());
      Serial.print(" PID: ");
      Serial.println(autoRoll.getOutput(AHRS::GetRollData(), updateTime));

      delay(50);
    }

    return 0;
}

