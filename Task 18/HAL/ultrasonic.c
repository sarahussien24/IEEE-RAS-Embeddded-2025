#include "ultrasonic.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define TRIG PD0
#define ECHO PD1

void ULTRASONIC_Init(void)
{
    DDRD |= (1 << TRIG);
    DDRD &= ~(1 << ECHO);
}

uint16_t ULTRASONIC_ReadDistance(void)
{
    uint16_t count = 0;

    PORTD &= ~(1 << TRIG);
    _delay_us(2);
    PORTD |= (1 << TRIG);
    _delay_us(10);
    PORTD &= ~(1 << TRIG);

    while (!(PIND & (1 << ECHO)));
    while (PIND & (1 << ECHO))
    {
        count++;
        _delay_us(1);
    }

    return (count / 58); 
}