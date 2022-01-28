//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"

#define NO_SENSOR 0x50

Sensor::Sensor(uint8_t nDim): senseDim(nDim) {
    senseBuffer = new uint16_t[nDim];
    senseVec    = new uint16_t *[nDim];
}

Sensor::~Sensor() {
    delete []senseBuffer;
    delete []senseVec;
}

byte Sensor::init(uint8_t *vecAddress[senseDim]){
    attach(vecAddress);
    return NO_ERROR;
}

byte Sensor::deinit(){}

byte Sensor::readSense(void){
    /* Template for reading physical sensor. Result of the read should be written to the read buffer*/

    for(i=0; i<senseDim; i++){senseBuffer[i] = 0;}
    return NO_SENSOR;
}

void Sensor::attach(uint8_t *vecAddress[senseDim]) {
    /* Attach addresses of sense vec to an external registry.*/
    for(i=0; i<senseDim; i++){senseVec[i] = vecAddress[i];}
}

byte Sensor::updateSense(void){
    // Attempt to read the sensor
    byte senseError = readSense();

    // Manage sensor errors
    if(senseError != NO_ERROR){return senseError;}

    else{
        // Transfer the buffer to the sense vector & return no error.
        for(i=0; i<senseDim; i++){senseVec[i] = readBuffer[i];}
        return NO_ERROR;
    }
}

