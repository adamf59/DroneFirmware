#include <Servo.h>
#include <Arduino.h>


namespace MCU {
    
    Servo _m1, _m2, _m3, _m4;

    void InitializeMotors() {

        _m1.attach(9);
        _m2.attach(10);
        _m3.attach(11);
        _m4.attach(12);
        
        Serial.println("Starting: SIGNAL HIGH");
        _m1.write(180);
        _m2.write(180);
        _m3.write(180);
        _m4.write(180);
        delay(5000);
        Serial.println("low point: SIGNAL LOW");
        _m1.write(0);
        _m2.write(0);
        _m3.write(0);
        _m4.write(0);
        delay(4000);
        Serial.println("speed up test in 3");
        delay(1000);
        Serial.println("speed up test in 2");
        delay(1000);
        Serial.println("speed up test in 1");
        delay(1000);
        Serial.println("speeding up...");
        for(int i = 0; i <= 180; i++) {
        _m1.write(i);
        _m2.write(i);
        _m3.write(i);
        _m4.write(i);
            delay(200);
        }
        Serial.println("now slowing down...");
        for(int i = 180; i >= 0; i--) {
            _m1.write(i);
            _m2.write(i);
            _m3.write(i);
            _m4.write(i);
            delay(200);
        }
        Serial.println("motor program completed.");
    }

    void ArmMotors() {
        
    }

    void SetMotorPower(int value) {

    }



}