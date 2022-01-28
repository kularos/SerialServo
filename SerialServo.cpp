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


SerialServo::SerialServo(uint16_t id, Sensor *sensorList, Actuator *actuatorList)
:identifier(id),
attachedSensors(sensorList), attachedActuators(actuatorList),
senseDim(calcSenseDim())   , controlDim(calcControlDim()) {

}; // must be initialized after sub-servo lists.


uint8_t SerialServo::calcControlDim() {

    // Initialize array for storing each actuator's controlDim.
    const uint8_t nActuator = *(&attachedActuators + 1) - attachedActuators;
    uint8_t actuatorDims[nActuator];

    // Iteratively fill actuatorDims from each attached actuator.
    for(uint8_t i = 0; i<nActuator; i++){
        actuatorDims[i] = attachedActuators[i].controlDim;
    }

    return actuatorDims;
}

uint8_t SerialServo::calcSenseDim() {

    // Initialize array for storing each sensor's senseDim.
    const uint8_t nSensor = *(&attachedSensors + 1) - attachedSensors;
    uint8_t sensorDims[nSensor];

    // Iteratively fill sensorDims from each attached sensor.
    for(uint8_t i = 0; i<nSensor; i++){
        sensorDims[i] = attachedSensors[i].senseDim;
    }

    return sensorDims;