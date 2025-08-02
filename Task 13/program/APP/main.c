#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/SSD/SSD_Interface.h"
#include "../HAL/LCD/LCD_Config.h"

#define RED_TIME     15
#define YELLOW_TIME  5
#define GREEN_TIME   10

void DisplayTwoDigits(u8 number) {
    u8 tens = number / 10;
    u8 ones = number % 10;
    
    SSD_voidPrintNumber(PORTC, COMMON_ANODE, tens);
    _delay_ms(5);   
    SSD_voidPrintNumber(PORTD, COMMON_CATHODE, ones);
    _delay_ms(5);
}
void CountDownWithLED(u8 seconds, u8 ledPort, u8 ledPin) {
    LED_voidStatus_Led_Pin(ledPort, ledPin, ON);
    
    for(u8 i = seconds; i > 0; i--) {
        for(u8 j = 0; j < 20; j++) {
            DisplayTwoDigits(i);
            _delay_ms(10);
        }
    }   
    LED_voidStatus_Led_Pin(ledPort, ledPin, OFF);
}
int main() {
    LED_voidInit_Led_Pin(PORTA, PIN0);
    LED_voidInit_Led_Pin(PORTA, PIN1);
    LED_voidInit_Led_Pin(PORTA, PIN2);
    
    SSD_voidInitSegmentPort(PORTC);
    SSD_voidInitSegmentPort(PORTD);
    
    while(1) {
        CountDownWithLED(RED_TIME, PORTA, PIN0);
        CountDownWithLED(GREEN_TIME, PORTA, PIN2);
        CountDownWithLED(YELLOW_TIME, PORTA, PIN1);
    }
    
    return 0;
}