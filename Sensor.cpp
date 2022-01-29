//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Sensor.h"

#define NO_SENSOR 0x50


// (De)initializers:
Sensor::Sensor(uint8_t nDim): senseDim(nDim) {
    senseVecAddress = new uint16_t *[nDim];
    senseBuffer     = new uint16_t  [nDim];
}

Sensor::~Sensor() {
    delete []senseVecAddress;
    delete []senseBuffer;
}


// Methods common to all sensors:
byte Sensor::getSense(void){
    // Attempt to read the sensor
    byte senseError = updateSense();

    // Manage sensor errors
    if(senseError != NO_ERROR){return senseError;}

    else{
        // Transfer the buffer to the sense vector & return no error.
        for(uint8_t i=0; i<senseDim; i++){*senseVecAddress[i] = senseBuffer[i];}
        return NO_ERROR;
    }
}

void Sensor::attach(uint16_t *vecAddress[]) {
    /* Attach addresses of sense vec to an external registry.*/
    for (uint8_t i = 0; i < senseDim; i++) { senseVecAddress[i] = vecAddress[i];}
}


// Methods intended to be overwritten in child sensors:
byte Sensor::init(uint16_t *vecAddress[]){
    attach(vecAddress); // Must attach during initialization.
    return NO_SENSOR;
}

byte Sensor::deinit(){
    return NO_SENSOR;
}

byte Sensor::updateSense(void){
    for(uint8_t i=0; i<senseDim; i++){senseBuffer[i] = 0;} // Template for reading physical sensor.
    return NO_SENSOR;
}
