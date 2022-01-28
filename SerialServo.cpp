//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"


int arrayTotal(int *arr){
    /* This function takes an integer array, and returns the sum of all entries.*/
    int arrLength = *(&arr + 1) - arr;

    int total = 0;
    for(int i = 0; i<arrLength; i++){
        total += arr[i];
    }

    return total;
}


SerialServo::SerialServo(uint16_t id, Sensor **sensorList, Actuator **actuatorList):
identifier(id),
attachedSensors(sensorList), attachedActuators(actuatorList),
senseDim(calcSenseDim()), controlDim(calcControlDim()) // must be initialized after sub-servo lists.
{

};

uint8_t SerialServo::calcControlDim() {

    // Initialize counter for total control dims in attached actuators.
    uint8_t nActuator = *(&attachedActuators + 1) - attachedActuators;
    uint8_t nDim = 0;

    // Iterate through all attached actuators, and
    for(uint8_t i = 0; i<nActuator; i++){
        nDim += attachedActuators[i].controlDim;
    }

    return nDim

}

uint8_t SerialServo::calcSenseDim() {

    // Initialize counter for total control dims in attached actuators.
    uint8_t nSensor = *(&attachedSensors + 1) - attachedSensors;
    uint8_t nDim = 0;

    // Iterate through all attached actuators, and
    for(uint8_t i = 0; i<nSensor; i++){
        nDim += attachedSensors[i].senseDim;
    }

    return nDim

}