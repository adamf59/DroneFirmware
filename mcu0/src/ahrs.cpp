#include "ahrs.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


namespace AHRS {

    Adafruit_BNO055 imu = Adafruit_BNO055(55);

    float _pitch = 0x00;
    float _yaw = 0x00;
    float _roll = 0x00;
    float _pitch_rate = 0x00;
    float _yaw_rate = 0x00;
    float _roll_rate = 0x00;

    const float GetPitchData() { return _pitch; }
    const float GetYawData() { return _yaw; }
    const float GetRollData() { return _roll; }
    const float GetPitchRateData() { return _pitch_rate; }
    const float GetYawDataData() { return _yaw_rate; }
    const float GetRollRateData() { return _roll_rate; }


    /*!
    *   @brief Pulls the most recent information from the IMU. Runs ~800 Hz maximum.
    */
    void __update__() {
        sensors_event_t event; 
        imu.getEvent(&event);

        _yaw = event.orientation.x;
        _pitch = event.orientation.y;
        _roll = event.orientation.z;


    }

    int __init__() {
        if(!imu.begin()) { return 1; } // Throw back an error if the IMU cannot be initialized
        imu.setExtCrystalUse(true);
        return 0;
    }
}