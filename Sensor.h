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
class Sensor{
public:
    Sensor(uint8_t n): nDim(n), senseVec[n]{0}, readBuffer[n]{0};      // Constructor

    const uint8_t nDim;                 // Number of dimensions in the sense vector this sensor receives.
    byte updateSense(void);             // calls readSense, and writes values to senseVec, returning the error code.

    void attach(uint16_t *vecAddress[]); // Binds the vector addresses to the servo.

private:
    byte senseError = NO_ERROR;         // Flag to track if the sense reading was bad.
    byte readSense(void);               // function to read sensor value

    uint16_t *senseVec [];              // Array of pointers to the uint16_t normalization of the sense vector.
    uint16_t readBuffer [];             // Buffer for storing values after read.
};



#endif //SERIALSERVO_SENSOR_H
