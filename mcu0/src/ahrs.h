#ifndef ATTITUDE_HEADING_REFERENCE_SYSTEM_H

#define ATTITUDE_HEADING_REFERENCE_SYSTEM_H

    namespace AHRS {

        const float GetPitchData();
        const float GetYawData();
        const float GetRollData();
        const float GetPitchRateData();
        const float GetYawDataData();
        const float GetRollRateData();


        int __init__();

        long __update__();
    }

#endif