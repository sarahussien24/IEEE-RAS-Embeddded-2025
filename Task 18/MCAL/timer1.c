#include "timer1.h"

void TIMER1_Init(void)
{
    TCCR1A = 0;
    TCCR1B = (1 << CS11);
}

uint16_t TIMER1_InputCapture(void)
{
    TCNT1 = 0;
    while (!(TIFR & (1 << ICF1)));
    TIFR |= (1 << ICF1);
    return ICR1;
}