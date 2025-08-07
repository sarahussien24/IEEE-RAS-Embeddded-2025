#include "motor.h"

void Motor_Init(void) {
    GPIO_SetPinDirection(&MOTOR_DDR, motorConfig.leftMotor.pin1, PIN_OUTPUT);
    GPIO_SetPinDirection(&MOTOR_DDR, motorConfig.leftMotor.pin2, PIN_OUTPUT);
    GPIO_SetPinDirection(&MOTOR_DDR, motorConfig.rightMotor.pin1, PIN_OUTPUT);
    GPIO_SetPinDirection(&MOTOR_DDR, motorConfig.rightMotor.pin2, PIN_OUTPUT);
    
    Motor_StopAll();
}

void Motor_SetDirection(MotorPins motor, MotorDirection direction) {
    switch(direction) {
        case MOTOR_FORWARD:
            GPIO_WritePin(&MOTOR_PORT, motor.pin1, PIN_HIGH);
            GPIO_WritePin(&MOTOR_PORT, motor.pin2, PIN_LOW);
            break;
        case MOTOR_BACKWARD:
            GPIO_WritePin(&MOTOR_PORT, motor.pin1, PIN_LOW);
            GPIO_WritePin(&MOTOR_PORT, motor.pin2, PIN_HIGH);
            break;
        case MOTOR_STOP:
        default:
            GPIO_WritePin(&MOTOR_PORT, motor.pin1, PIN_LOW);
            GPIO_WritePin(&MOTOR_PORT, motor.pin2, PIN_LOW);
    }
}

void Motor_StopAll(void) {
    GPIO_WritePin(&MOTOR_PORT, motorConfig.leftMotor.pin1, PIN_LOW);
    GPIO_WritePin(&MOTOR_PORT, motorConfig.leftMotor.pin2, PIN_LOW);
    GPIO_WritePin(&MOTOR_PORT, motorConfig.rightMotor.pin1, PIN_LOW);
    GPIO_WritePin(&MOTOR_PORT, motorConfig.rightMotor.pin2, PIN_LOW);
}

void Motor_MoveForward(void) {
    Motor_SetDirection(motorConfig.leftMotor, MOTOR_FORWARD);
    Motor_SetDirection(motorConfig.rightMotor, MOTOR_FORWARD);
}

void Motor_MoveBackward(void) {
    Motor_SetDirection(motorConfig.leftMotor, MOTOR_BACKWARD);
    Motor_SetDirection(motorConfig.rightMotor, MOTOR_BACKWARD);
}

void Motor_TurnLeft(void) {
    Motor_SetDirection(motorConfig.leftMotor, MOTOR_STOP);
    Motor_SetDirection(motorConfig.rightMotor, MOTOR_FORWARD);
}

void Motor_TurnRight(void) {
    Motor_SetDirection(motorConfig.leftMotor, MOTOR_FORWARD);
    Motor_SetDirection(motorConfig.rightMotor, MOTOR_STOP);
}

void Motor_CustomMove(MotorDirection left, MotorDirection right) {
    Motor_SetDirection(motorConfig.leftMotor, left);
    Motor_SetDirection(motorConfig.rightMotor, right);
}