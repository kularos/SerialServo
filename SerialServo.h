//
// Created by ianku on 2022-01-23.
//

/*
* --- Servo interface ---
* In general, a servo is comprised of a set of inputs, outputs and a control function.
* To simplify, these c++ sensors will be 100% transparent (no feedback or feed-forward)
*    - Thus, they don't need to worry about control loops or error.
*
*  The only methods they need to implement in order to fit the interface are:
*    - open a stream:      OPEN()
*    - close a stream:     ClOSE()
*    - set control vector: SET_CTL()
*    - get sensor data:    GET_SNS()
*
*  As these are physical devices, they also stand to implement methods to specify the physical parameters of the device:
*    - retrieve information about the device: GET_INFO() is going to be an asynchronous communication (duration unspecified) and should include:
*      (read only) - An identifier that is unique to the device.
*      (read only) - Specifications on the expected number of bytes in each communication (GET_SNS, SET_CTL, CALIBRATE), and how these bytes correspnd to an i/o vector.
*      - These two communications should be separated to allow the upladder node to
*/

#ifndef SERIALSERVO_SERIALSERVO_H
#define SERIALSERVO_SERIALSERVO_H
#include <Arduino.h>

// Serial interface byte definitions:
#define END_BYTE       0x0A

#define OPEN           0x20
#define GET_ID         0x21
#define CLOSE          0x22
#define RESET          0x23
#define GET_SENSE      0x24
#define SET_CONTROL    0x25

#define NO_ERROR       0x40  // No error occured during command execution.
#define CMD_VAL_ERROR  0x41  // An unknown command byte was provided.
#define CMD_NUL_ERROR  0x42  // A command was executed before assignment.
#define CMD_EXE_ERROR  0x43  // An error occured during command execution.
#define DAT_IDX_ERROR  0x44  // The provided amount of data was not consistent with the expected amount for the command.
#define RSP_IDX_ERROR  0x45  // The generated response was not consistent with the expected length for the command.

#define CONTROL_ERROR  0x4A
#define SENSOR_ERROR   0x49


//#define uint8_t unsigned char
//#define uint16_t unsigned short int

// Serial Command structure and definitions.
typedef struct{
    byte byteCode;         // The command byte that triggers execution of this command.
    byte (*executeFunc)(void); // A pointer to the function that is called upon this command's execution.
    uint8_t dataBytes;     // The number of data bytes that are expected to be transmitted alongside this command.
    uint8_t responseBytes; // The number of bytes that are expected to comprise this command's response.
} command;



class SerialServo{

};


#endif //SERIALSERVO_SERIALSERVO_H