//
// Created by ianku on 2022-01-25.
//

#ifndef SERIALSERVO_SENSOR_H
#define SERIALSERVO_SENSOR_H
#include "SerialServo.h"


#define SENSOR_ERROR   0x49

// Sensor class definitions.
// child classes must overwrite methods for initialization, de-initialization, and reading.
class Sensor{
public:
    const uint8_t senseDim;                // Number of dimensions in the sense vector this sensor receives.
    Sensor(uint8_t nDim);                   // Constructor takes number of dimensions.
    ~Sensor();
    byte init(uint8_t *vecAddress[]);      // Initializer of the sensor, returns error code.
    byte deinit();                          // de-initializer.
    byte updateSense(void);                 // calls readSense, writes to senseVec, and returns error code.
private:
    void attach(uint8_t *vecAddress[]);    // Binds the vector addresses to the servo.
    byte readSense(void);                   // function to read sensor value
    uint16_t **senseVec;                    // Array of pointers to the uint16_t values of the sense vector.
    uint16_t *senseBuffer;                  // Buffer for storing values after read.
};



#endif //SERIALSERVO_SENSOR_H
