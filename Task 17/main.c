#include "gpio.h"
#include "adc.h"
#include "lcd.h"
#include <stdio.h>

int main(void) {
    char buffer[16];
    uint16_t adc_value;
    uint8_t led_count;
    uint8_t percent;

    GPIO_Init();
    ADC_Init();
    LCD_Init();

    while(1) {
        adc_value = ADC_Read(0);
        percent = (uint8_t)(((uint32_t)adc_value * 100UL) / 1023UL);
        led_count = (percent * 8) / 100;

        GPIO_SetLEDs(led_count);

        LCD_Clear();
        LCD_SetCursor(0,0);
        sprintf(buffer, "ADC=%4d", adc_value);
        LCD_String(buffer);

        LCD_SetCursor(1,0);
        sprintf(buffer, "P=%3d%%", percent);
        LCD_String(buffer);

        _delay_ms(200);
    }
}