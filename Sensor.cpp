//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"

Sensor::Sensor(uint8_t n){
    nDim = n;
    senseVec[nDim];
    readBuffer[nDim];
}

byte Sensor::updateSense(void){
    // Attempt to read the sensor
    senseError = readSense();

    // Manage sensor errors
    if(senseError != NO_ERROR){
        return senseError;
    }
    else{ return NO_ERROR}
}

