#include "MCAL/timer0.h"
#include "MCAL/timer1.h"
#include "MCAL/adc.h"
#include "MCAL/gpio.h"
#include "MCAL/wdt.h"
#include "HAL/lcd.h"
#include "HAL/ultrasonic.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    uint16_t adcValue;
    uint8_t pwmValue;
    uint16_t distance;

    GPIO_Init();
    ADC_Init();
    TIMER0_Init_PWM();
    TIMER1_Init();
    LCD_Init();
    LCD_Init();
    LCD_Clear();
    LCD_String("System Ready");
    ULTRASONIC_Init();
    WDT_Enable();


    while (1)
    {
        adcValue = ADC_Read(0); 
        pwmValue = (adcValue * 255UL) / 1023;
        TIMER0_SetPWM(pwmValue);

        distance = ULTRASONIC_ReadDistance();
        LCD_Clear();
        LCD_String("Dist:");
        LCD_Number(distance);
        LCD_String(" cm");

        WDT_Reset();

        _delay_ms(100);
    }
}