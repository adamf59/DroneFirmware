#include "pid_controller.h"

    

    PIDController::PIDController(float kP, float kI,float kD) {
    _kP = kP;
    _kI = kI;
    _kD = kD;
    _targetPosition = 0;
    _timeIntegral = 0;
    _lastMeasurement = 0;
    _lastMeasurementTime = 0L;
    }

    void PIDController::setTarget(float target) {
        _targetPosition = target;
    }

    /*!
        @brief Resets this PID controller.
    */
    void PIDController::reset() {
        _timeIntegral = _targetPosition = 0;
    }
    
    float PIDController::getOutput(float _currentPosition, long measurementTime) {
        float targetError = _currentPosition - _targetPosition;
        
        // sum the next integral:
        _timeIntegral += targetError * (measurementTime-_lastMeasurementTime);

        float output = 0;
        // Calculate proportional output
        output += (_kP * targetError);
        // Calculate integral output
        output += (_kI * _timeIntegral);
        // Calculate derivative output
        output += _kD * ((targetError-(_lastMeasurement-_targetPosition))/(measurementTime-_lastMeasurementTime));


        // Finally, update the variables for the next loop.
        _lastMeasurement = _currentPosition;
        _lastMeasurementTime = measurementTime;

        return output;
    }




