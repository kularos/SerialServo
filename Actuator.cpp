//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"
#include "Actuator.h"

#define NO_ACTUATOR 0x51


// (De)initializers:
Actuator::Actuator(uint8_t nDim): controlDim(nDim) {
    controlVecAddress = new uint16_t *[nDim];
}

Actuator::~Actuator() {
    delete []controlVecAddress;
}


// Methods common to all actuators:


void Actuator::attach(uint16_t *vecAddress[]) {
    /* Attach addresses of control vec to an external registry.*/
    for (uint8_t i = 0; i < controlDim; i++) { controlVecAddress[i] = vecAddress[i]; }
}


// Methods intended to be overwritten in child actuators:
byte Actuator::init(uint16_t *vecAddress[]) {
    attach(vecAddress); // Must attach during initialization.
    return NO_ACTUATOR;
}

byte Actuator::deinit() {
    return NO_ACTUATOR;
}

byte Actuator::setControl() {
    return NO_ACTUATOR;
}
