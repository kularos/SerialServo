//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"

#define NO_SENSOR 0x50

void Sensor::Sensor(uint8_t nDim) {
    sensorDim = nDim;

    readBuffer = new  uint16_t[nDim];
    senseVec   = new *uint16_t[nDim];
}

void Sensor::~Sensor() {
    delete []readBuffer;
    delete []senseVec;
}

byte Sensor::readSense(void){
    return NO_SENSOR;
}

byte Sensor::updateSense(void){
    // Attempt to read the sensor
    byte senseError = readSense();

    // Manage sensor errors
    if(senseError != NO_ERROR){
        return senseError;
    }
    else{return NO_ERROR;}
}

