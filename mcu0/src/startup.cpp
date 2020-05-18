/**
Drone MCU0 AVR Program
*/
#include <Arduino.h>
#include "ahrs.h"
#include "pid_controller.h"
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
      delay(3000);
      MCU::ArmMotors();
      Serial.println(F("[  OK  ] Motor Control Unit initialized, motors armed."));
    
    PIDController autoRoll(-.4015,-0.00003,0.1);
    autoRoll.setTarget(0);
    for (;;) {
      long updateTime = AHRS::__update__();

      Serial.print("Roll: ");
      Serial.print(AHRS::GetRollData());
      Serial.print(" PID: ");
      float output = autoRoll.getOutput(AHRS::GetRollData(), updateTime);
      Serial.println(output);

      float m1 = 50 + output;
      float m2 = 50 - output;
      float m3 = 50 - output;
      float m4 = 50 + output;

      MCU::SetMotorPower(m1, m2, m3, m4);



      delay(200);
    }

    return 0;
}

