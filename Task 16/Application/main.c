#include "../Libraries/STD_TYPES.h"
#include "../Libraries/BIT_MATH.h"
#include "../Drivers/DIO/DIO.h"
#include "../Drivers/EXTI/EXTI0.h"
#include "../Drivers/EXTI/EXTI1.h"
#include "../Drivers/Seven_Segment/SEVEN_SEG.h"
#include "../Drivers/LCD/LCD.h"
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8 counter=1;
volatile uint8 led_state=0;

void INT0_Callback(void){
    led_state^=1;
    DIO_SetPinValue(DIO_PORTC,DIO_PIN0,led_state);
}
void INT1_Callback(void){
    counter=0;
    SEVEN_SEG_DisplayNumber(counter);
    LCD_GoTo(0,0); LCD_SendString("Counter: "); LCD_DisplayNumber(counter);
}

int main(void){
    SEVEN_SEG_Init();
    LCD_Init();
    DIO_SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);

    EXTI0_Init(EXTI0_FALLING_EDGE); EXTI0_SetCallBack(INT0_Callback); EXTI0_Enable();
    EXTI1_Init(EXTI1_FALLING_EDGE); EXTI1_SetCallBack(INT1_Callback); EXTI1_Enable();

    sei();

    LCD_SendString("Counter: "); LCD_DisplayNumber(counter);

    while(1){
        _delay_ms(1000);
        counter++;
        if(counter>9) counter=1;
        SEVEN_SEG_DisplayNumber(counter);
        LCD_GoTo(0,0); LCD_SendString("Counter: "); LCD_DisplayNumber(counter);
    }
}