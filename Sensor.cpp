//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"

Sensor::updateSense(void){
    // Attempt to read the sensor
    raw_sense = readSense();

    if(senseError != NO_ERROR)

}

