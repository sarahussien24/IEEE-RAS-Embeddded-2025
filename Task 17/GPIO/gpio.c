#include "gpio.h"

void GPIO_Init(void) {
    LED_DDR = 0xFF;
    LED_PORT = 0x00;
}

void GPIO_SetLEDs(uint8_t count) {
    if(count > 8) count = 8;
    LED_PORT = (1 << count) - 1;
}