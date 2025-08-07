#include "gpio.h"

void GPIO_SetPinDirection(volatile uint8_t *ddr, uint8_t pin, PinDirection direction) {
    if (direction == PIN_OUTPUT) {
        *ddr |= (1 << pin);
    } else {
        *ddr &= ~(1 << pin);
    }
}

void GPIO_WritePin(volatile uint8_t *port, uint8_t pin, PinState state) {
    switch(state) {
        case PIN_HIGH:
            *port |= (1 << pin);
            break;
        case PIN_LOW:
            *port &= ~(1 << pin);
            break;
        case PIN_TOGGLE:
            *port ^= (1 << pin);
            break;
    }
}

uint8_t GPIO_ReadPin(volatile uint8_t *pinReg, uint8_t pin) {
    return (*pinReg & (1 << pin)) ? PIN_HIGH : PIN_LOW;
}