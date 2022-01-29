//
// Created by ianku on 2022-01-25.
//

#ifndef SERIALSERVO_SENSOR_H
#define SERIALSERVO_SENSOR_H
#include "SerialServo.h"


#define SENSOR_ERROR   0x49

/* Sensor class definitions.
 * For sensing, data flows from the environment to the machine, so the get operation must be buffered.
 * Actuators do not have a defined set operation. */

// Child classes must overwrite methods for initialization, de-initialization, and reading.
class Sensor{

public:
    Sensor(uint8_t nDim);                   // Constructor only takes number of dimensions.
    ~Sensor();                              // Since addresses aren't necessarily known at construction.

    uint8_t senseDim;                 // Number of dimensions in the sense vector that this sensor receives.
    byte init(uint16_t *vecAddress[]);      // Initializer of the sensor, returns error code.
    byte deinit();                          // De-initializer.
    byte getSense(void);                    // Calls readSense, writes to senseVec, and returns error code.

private:
    uint16_t **senseVecAddress;             // Array of pointers to the uint16_t values of the sense vector.
    void attach(uint16_t *vecAddress[]);    // Binds the vector addresses to the servo.

    uint16_t *senseBuffer;                  // Buffer for storing values after read.
    byte updateSense(void);                 // Function to read sensor value into the sense buffer.
};

#endif //SERIALSERVO_SENSOR_H
