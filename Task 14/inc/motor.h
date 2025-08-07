#ifndef MOTOR_H
#define MOTOR_H

#include "gpio.h"
#include "config.h"

typedef enum {
    MOTOR_STOP,
    MOTOR_FORWARD,
    MOTOR_BACKWARD
} MotorDirection;

typedef struct {
    uint8_t pin1;
    uint8_t pin2;
} MotorPins;

typedef struct {
    MotorPins leftMotor;
    MotorPins rightMotor;
} MotorConfig;

static const MotorConfig motorConfig = {
    .leftMotor = {PB0, PB1},
    .rightMotor = {PB2, PB3}
};

void Motor_Init(void);
void Motor_SetDirection(MotorPins motor, MotorDirection direction);
void Motor_StopAll(void);
void Motor_MoveForward(void);
void Motor_MoveBackward(void);
void Motor_TurnLeft(void);
void Motor_TurnRight(void);
void Motor_CustomMove(MotorDirection left, MotorDirection right);

#endif