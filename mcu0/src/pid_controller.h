#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController {
    
    private:
        float _kP; // Konstant for proportional controller
        float _kI; // Konstant for integral controller
        float _kD; // Konstant for derivative controller
        float _targetPosition; // commonly called the "setpoint"
        float _timeIntegral = 0.00;   
        float _lastMeasurement = 0.00;
        long  _lastMeasurementTime = 0;
        
    public:

        PIDController(float kP, float kI, float kD);

        void setTarget(float target);
        float getOutput(float _currentPosition, long measurementTime);
         void reset();

    };

#endif