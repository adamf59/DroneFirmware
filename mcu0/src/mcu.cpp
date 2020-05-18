#include <Servo.h>
#include <Arduino.h>
#include "mcu.h"


namespace MCU {
    
    Servo _m1, _m2, _m3, _m4;

    void InitializeMotors() {

        _m1.attach(9);
        _m2.attach(10);
        _m3.attach(11);
        _m4.attach(12);
        SetMotorPower(0, 0, 0, 0);
    }

    void ArmMotors() {
        
    }

    void SetMotorPower(int m1, int m2, int m3, int m4) {
        _m1.write(m1);
        _m2.write(m2);
        _m3.write(m3);
        _m4.write(m4);
    }

    void executeIncentive(float roll, float pitch, float yaw, float altitude) {
            // lets assume altitude is holding the motors at power = 50 for example
            altitude = 50;

            // sum motor 1:
            float m1_setting = 0;


    }



}