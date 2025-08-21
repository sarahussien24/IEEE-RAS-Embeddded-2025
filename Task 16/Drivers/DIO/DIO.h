#ifndef DIO_H_
#define DIO_H_

#include "../Libraries/STD_TYPES.h"

typedef enum {DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD} DIO_Port_t;
typedef enum {DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3,
              DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7} DIO_Pin_t;

typedef enum {DIO_PIN_INPUT, DIO_PIN_OUTPUT} DIO_PinDirection_t;
typedef enum {DIO_PIN_LOW, DIO_PIN_HIGH} DIO_PinValue_t;
typedef enum {DIO_PORT_INPUT, DIO_PORT_OUTPUT} DIO_PortDirection_t;

void DIO_SetPinDirection(DIO_Port_t port, DIO_Pin_t pin, DIO_PinDirection_t dir);
void DIO_SetPinValue(DIO_Port_t port, DIO_Pin_t pin, DIO_PinValue_t val);
void DIO_SetPortDirection(DIO_Port_t port, DIO_PortDirection_t dir);
void DIO_SetPortValue(DIO_Port_t port, uint8 val);

#endif