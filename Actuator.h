//
// Created by ianku on 2022-01-25.
//

#ifndef SERIALSERVO_ACTUATOR_H
#define SERIALSERVO_ACTUATOR_H
#include "SerialServo.h"


#define SENSOR_ERROR   0x49

/* Actuator class definitions.
 * For actuation, data flows from the machine to the environment, so the set operation can be unbuffered.
 * Actuators do not have a defined get operation. */

// child classes must overwrite methods for initialization, de-initialization, and writing.
class Actuator{

public:
    Actuator(uint8_t nDim);                 // Constructor only takes number of dimensions,
    ~Actuator();                            // Since addresses aren't necessarily known at construction.

    const uint8_t controlDim;               // Number of dimensions in the control vector that this actuator receives.
    byte init(uint16_t *vecAddress[]);      // Initializer of the actuator, returns error code.
    byte deinit();                          // de-initializer.
    byte setControl(void);                  // function to write values from control vector to actuator.

private:
    uint16_t **controlVecAddress;           // Array of pointers to the uint16_t values of the sense vector.
    void attach(uint16_t *vecAddress[]);    // Binds the vector addresses to the servo.
};

#endif //SERIALSERVO_ACTUATOR_H
