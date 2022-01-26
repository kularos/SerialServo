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
    const uint8_t nDim;              // Number of dimensions in the sense vector this sensor receives.
    byte updateSense(void);    // calls readSense, and writes values to senseVec, returning the error code.

private:
    uint16_t *senseVec [];       // Array of pointers to the uint16_t normalization of the sense vector.
    byte senseError = NO_ERROR;     // Flag to set the track if the sense reading was bad.
    uint16_t[] readSense(void); // function to read sensor value

}



#endif //SERIALSERVO_SENSOR_H
