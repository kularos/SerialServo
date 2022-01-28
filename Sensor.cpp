//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"

#define NO_SENSOR 0x50

// (De)initializers:
Sensor::Sensor(uint8_t nDim): senseDim(nDim) {
    senseBuffer = new uint16_t[nDim];
    senseVec    = new uint16_t *[nDim];
}

Sensor::~Sensor() {
    delete []senseBuffer;
    delete []senseVec;
}

// Methods common to all sensors:
void Sensor::attach(uint16_t *vecAddress[]) {
    /* Attach addresses of sense vec to an external registry.*/
    for(uint8_t i=0; i<senseDim; i++){senseVec[i] = vecAddress[i];}
}

byte Sensor::updateSense(void){
    // Attempt to read the sensor
    byte senseError = readSense();

    // Manage sensor errors
    if(senseError != NO_ERROR){return senseError;}

    else{
        // Transfer the buffer to the sense vector & return no error.
        for(uint8_t i=0; i<senseDim; i++){*senseVec[i] = senseBuffer[i];}
        return NO_ERROR;
    }
}

// Methods intended to be overwritten in child sensors:
byte Sensor::init(uint16_t *vecAddress[]){
    attach(vecAddress);
    return NO_SENSOR;
}

byte Sensor::deinit(){
    return NO_SENSOR;
}

byte Sensor::readSense(void){
    /* Template for reading physical sensor. Result of the read should be written to the read buffer*/

    for(uint8_t i=0; i<senseDim; i++){senseBuffer[i] = 0;}
    return NO_SENSOR;
}
