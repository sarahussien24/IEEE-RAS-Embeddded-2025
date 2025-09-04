#include "wdt.h"

void WDT_Enable(void)
{
    WDTCR = (1 << WDE) | (1 << WDP1) | (1 << WDP0);
}

void WDT_Reset(void)
{
    __asm__ __volatile__ ("wdr");
}