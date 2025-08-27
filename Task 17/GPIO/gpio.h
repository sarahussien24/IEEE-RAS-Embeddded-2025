#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>

#define LED_PORT   PORTC
#define LED_DDR    DDRC

void GPIO_Init(void);
void GPIO_SetLEDs(uint8_t count);

#endif