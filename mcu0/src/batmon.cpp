#include "batmon.h"
#include <Arduino.h>

#define     BATTERY_MONITOR_INPUT       A0
#define     CHARGED_BATTERY_VOLTAGE     12.6
#define     LOW_THRESHOLD_VOLTAGE       10.5
#define     VD_R1                       2130
#define     VD_R2                       971


namespace BATTERY_MONITOR {

    float last_voltage = 0x00;
    float this_voltage = 0x00;

    bool __update__() {
        this_voltage = ((((5.0/1023.0)*analogRead(BATTERY_MONITOR_INPUT)) - .08)*(VD_R1+VD_R2))/VD_R2;
        return this_voltage >= LOW_THRESHOLD_VOLTAGE;
    }
    const float GetLatestVoltage() { return this_voltage; }




}