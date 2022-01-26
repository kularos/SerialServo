//
// Created by ianku on 2022-01-25.
//

#ifndef SERIALSERVO_ACTUATOR_H
#define SERIALSERVO_ACTUATOR_H

#include "SerialServo.h"


#define SENSOR_ERROR   0x49

// Sensor and actuator structural definitions.
class Actuator{
public:
    Actuator(uint8_t nDim);      // Constructor
    ~Actuator();
    void attach(uint16_t *vecAddress[]); // Binds the vector addresses to the servo.

    const uint8_t actuatorDim;             // Number of dimensions in the sense vector this sensor receives.
    byte updateActuator(void);             // calls readSense, and writes values to senseVec, returning the error code.

private:

    uint16_t **actuatorVec;              // Array of pointers to the uint16_t normalization of the sense vector.
};

#endif //SERIALSERVO_ACTUATOR_H
