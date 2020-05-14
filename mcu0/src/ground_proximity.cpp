// ALL MEASUREMENTS ARE IN UNITS OF CM, MILLISECONDS UNLESS OTHERWISE DENOTED

#include <Arduino.h>

namespace GROUND_PROXIMITY {

#define     PROXIMITY_SENSOR_TRIGGER    7
#define     PROXIMITY_SENSOR_ECHO       8    


    long lastProximityTime = 0;
    float lastProximity = 0;
    long latestProximityTime = 0;
    float latestProximity = 0;

    void __init__() {
        pinMode(PROXIMITY_SENSOR_TRIGGER, OUTPUT);
        pinMode(PROXIMITY_SENSOR_ECHO, INPUT);
    }

    void __update__() {
        lastProximity = latestProximity;
        lastProximityTime = latestProximityTime;

        digitalWrite(PROXIMITY_SENSOR_TRIGGER, 1);
        delayMicroseconds(10);
        digitalWrite(PROXIMITY_SENSOR_TRIGGER, 0);

        latestProximityTime = millis(); // this needs to be as close as possible to the actual reading time.
        latestProximity = (pulseIn(PROXIMITY_SENSOR_ECHO, 1)*0.034)/2.0;

    }

    float getRadarVerticalSpeed() {
        float calculatedSpeed = (latestProximity-lastProximity)/(latestProximityTime-lastProximityTime)*100;
        return abs(calculatedSpeed) > 1 ? calculatedSpeed : 0.00;
    }

    float getProximity() {
        return latestProximity;
    }

}

