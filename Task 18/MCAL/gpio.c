#include "gpio.h"

void GPIO_Init(void)
{
    DDRC = 0xFF;
    DDRD |= (1 << PD0);
    DDRD &= ~(1 << PD1);
}