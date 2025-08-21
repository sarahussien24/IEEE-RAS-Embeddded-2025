#include "DIO.h"
#include "BIT_MATH.h"

#define PORTA_REG (*(volatile uint8*)0x3B)
#define DDRA_REG  (*(volatile uint8*)0x3A)
#define PINA_REG  (*(volatile uint8*)0x39)

#define PORTB_REG (*(volatile uint8*)0x38)
#define DDRB_REG  (*(volatile uint8*)0x37)
#define PINB_REG  (*(volatile uint8*)0x36)

#define PORTC_REG (*(volatile uint8*)0x35)
#define DDRC_REG  (*(volatile uint8*)0x34)
#define PINC_REG  (*(volatile uint8*)0x33)

#define PORTD_REG (*(volatile uint8*)0x32)
#define DDRD_REG  (*(volatile uint8*)0x31)
#define PIND_REG  (*(volatile uint8*)0x30)

void DIO_SetPinDirection(DIO_Port_t port, DIO_Pin_t pin, DIO_PinDirection_t direction) {
    switch(port) {
        case DIO_PORTA:
            if (direction == DIO_PIN_OUTPUT) {
                SET_BIT(DDRA_REG, pin);
            } else {
                CLR_BIT(DDRA_REG, pin);
            }
            break;
        case DIO_PORTB:
            if (direction == DIO_PIN_OUTPUT) {
                SET_BIT(DDRB_REG, pin);
            } else {
                CLR_BIT(DDRB_REG, pin);
            }
            break;
        case DIO_PORTC:
            if (direction == DIO_PIN_OUTPUT) {
                SET_BIT(DDRC_REG, pin);
            } else {
                CLR_BIT(DDRC_REG, pin);
            }
            break;
        case DIO_PORTD:
            if (direction == DIO_PIN_OUTPUT) {
                SET_BIT(DDRD_REG, pin);
            } else {
                CLR_BIT(DDRD_REG, pin);
            }
            break;
    }
}

void DIO_SetPinValue(DIO_Port_t port, DIO_Pin_t pin, DIO_PinValue_t value) {
    switch(port) {
        case DIO_PORTA:
            if (value == DIO_PIN_HIGH) {
                SET_BIT(PORTA_REG, pin);
            } else {
                CLR_BIT(PORTA_REG, pin);
            }
            break;
        case DIO_PORTB:
            if (value == DIO_PIN_HIGH) {
                SET_BIT(PORTB_REG, pin);
            } else {
                CLR_BIT(PORTB_REG, pin);
            }
            break;
        case DIO_PORTC:
            if (value == DIO_PIN_HIGH) {
                SET_BIT(PORTC_REG, pin);
            } else {
                CLR_BIT(PORTC_REG, pin);
            }
            break;
        case DIO_PORTD:
            if (value == DIO_PIN_HIGH) {
                SET_BIT(PORTD_REG, pin);
            } else {
                CLR_BIT(PORTD_REG, pin);
            }
            break;
    }
}

DIO_PinValue_t DIO_GetPinValue(DIO_Port_t port, DIO_Pin_t pin) {
    switch(port) {
        case DIO_PORTA:
            return GET_BIT(PINA_REG, pin);
        case DIO_PORTB:
            return GET_BIT(PINB_REG, pin);
        case DIO_PORTC:
            return GET_BIT(PINC_REG, pin);
        case DIO_PORTD:
            return GET_BIT(PIND_REG, pin);
        default:
            return DIO_PIN_LOW;
    }
}

void DIO_SetPortDirection(DIO_Port_t port, DIO_PortDirection_t direction) {
    switch(port) {
        case DIO_PORTA:
            DDRA_REG = (direction == DIO_PORT_OUTPUT) ? 0xFF : 0x00;
            break;
        case DIO_PORTB:
            DDRB_REG = (direction == DIO_PORT_OUTPUT) ? 0xFF : 0x00;
            break;
        case DIO_PORTC:
            DDRC_REG = (direction == DIO_PORT_OUTPUT) ? 0xFF : 0x00;
            break;
        case DIO_PORTD:
            DDRD_REG = (direction == DIO_PORT_OUTPUT) ? 0xFF : 0x00;
            break;
    }
}

void DIO_SetPortValue(DIO_Port_t port, uint8 value) {
    switch(port) {
        case DIO_PORTA:
            PORTA_REG = value;
            break;
        case DIO_PORTB:
            PORTB_REG = value;
            break;
        case DIO_PORTC:
            PORTC_REG = value;
            break;
        case DIO_PORTD:
            PORTD_REG = value;
            break;
    }
}