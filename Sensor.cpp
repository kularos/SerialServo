//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"


byte Sensor::updateSense(void){
    // Attempt to read the sensor
    byte senseError = readSense();

    // Manage sensor errors
    if(senseError != NO_ERROR){
        return senseError;
    }
    else{ return NO_ERROR}
}

