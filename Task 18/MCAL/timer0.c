#include "timer0.h"

void TIMER0_Init_PWM(void)
{
    DDRB |= (1 << PB3);
    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01); 
}

void TIMER0_SetPWM(uint8_t value)
{
    OCR0 = value;
}