//
// Created by ianku on 2022-01-25.
//

#ifndef SERIALSERVO_SENSOR_H
#define SERIALSERVO_SENSOR_H
#include "SerialServo.h"

#include <Wire.h>
#include "Adafruit_SHT31.h"

#define SENSOR_ERROR   0x49

// Sensor and actuator structural definitions.
template <uint8_t nDim>
class Sensor{
public:
    Sensor(): sensorDim(nDim), senseVec{0}, readBuffer{0} {};      // Constructor

    const uint8_t sensorDim;                 // Number of dimensions in the sense vector this sensor receives.
    byte updateSense(void);             // calls readSense, and writes values to senseVec, returning the error code.

    void attach(uint16_t *vecAddress[]); // Binds the vector addresses to the servo.

private:
    byte senseError = NO_ERROR;         // Flag to track if the sense reading was bad.
    byte readSense(void);               // function to read sensor value

    uint16_t *senseVec[nDim];              // Array of pointers to the uint16_t normalization of the sense vector.
    uint16_t readBuffer[nDim];             // Buffer for storing values after read.
};



#endif //SERIALSERVO_SENSOR_H
