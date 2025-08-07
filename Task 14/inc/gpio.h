#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

typedef enum {
    PIN_INPUT = 0,
    PIN_OUTPUT = 1
} PinDirection;

typedef enum {
    PIN_LOW = 0,
    PIN_HIGH = 1,
    PIN_TOGGLE = 2
} PinState;

void GPIO_SetPinDirection(volatile uint8_t *ddr, uint8_t pin, PinDirection direction);
void GPIO_WritePin(volatile uint8_t *port, uint8_t pin, PinState state);
uint8_t GPIO_ReadPin(volatile uint8_t *pinReg, uint8_t pin);

#endif