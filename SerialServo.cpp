//
// Created by ianku on 2022-01-25.
//

#include "SerialServo.h"


const uint8_t arrayTotal(uint8_t *arr){
    /* This function takes an integer array, and returns the sum of all entries.*/
    uint8_t arrLength = *(&arr + 1) - arr;

    uint8_t total = 0;
    for(uint8_t i = 0; i<arrLength; i++){
        total += arr[i];
    }

    return total;
}


SerialServo::SerialServo(uint16_t id, Sensor *sensorList, Actuator *actuatorList)
:identifier(id),
attachedSensors(sensorList), attachedActuators(actuatorList),
senseDimVector(calcSenseDim()), controlDimVector(calcControlDim()),
senseDim(arrayTotal(senseDimVector)), controlDim(arrayTotal(controlDimVector))
{
    // Initialize control and sense vectors.
    controlVector = new uint16_t[controlDim];
    senseVector   = new uint16_t[senseDim];

    // Attach all downstream sub-servos:

    uint8_t i = 0; // indexer for full sense vector.
    for(uint8_t j = 0; j<nSensor; j++){

        // initialize vecAddress for sensor j.
        const uint8_t nSensej = senseDimVector[j];
        uint16_t *vecAddress[nSensej];

        // iteratively fill vecAddress and attach sensor j.
        for(uint8_t k = 0; k<nSensej; k++){vecAddress[k] = &senseVector[i]; i++;}
        attachedSensors[j].attach(senseVector);
    }

    i = 0; // indexer for full control vector.
    for(uint8_t j = 0; j<nActuator; j++){

        // Initialize vecAddress for actuator j.
        const uint8_t nControlj = controlDimVector[j];
        uint16_t *vecAddress[nControlj];

        // Iteratively fill vecAddress and attach sensor j.
        for(uint8_t k = 0; k<nControlj; k++){vecAddress[k] = &controlVector[i]; i++;}
        attachedActuators.attach(vecAddress);
    }
}


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
    for (uint8_t i = 0; i < nSensor; i++) {
        sensorDims[i] = attachedSensors[i].senseDim;
    }

    return sensorDims;
}