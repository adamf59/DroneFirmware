#ifndef MOTOR_CONTROL_UNIT_H
#define MOTOR_CONTROL_UNIT_H

namespace MCU {

    void SetMotorPower(int m1, int m2, int m3, int m4);
    void InitializeMotors();
    void ArmMotors();
}

#endif