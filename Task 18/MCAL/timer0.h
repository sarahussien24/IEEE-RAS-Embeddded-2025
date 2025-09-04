#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/io.h>

void TIMER0_Init_PWM(void);
void TIMER0_SetPWM(uint8_t value);

#endif