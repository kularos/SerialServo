//
// Created by ianku on 2022-01-25.
//

#ifndef SERIALSERVO_ACTUATOR_H
#define SERIALSERVO_ACTUATOR_H

class Actuator{
    uint8_t nDim;               // Number of dimensions in the control vector this actuator receives.
    uint16_t *controlVec[nDim]; // Array of pointers to the uint16_t normalization of the control vector.

    byte (*updateControl)(void);        // physically writes control vector to peripheral devices.
};


#endif //SERIALSERVO_ACTUATOR_H
