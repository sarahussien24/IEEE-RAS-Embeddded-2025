#include "LCD.h"
#include "DIO.h"
#include <util/delay.h>

#define LCD_RS DIO_PIN0
#define LCD_RW DIO_PIN1
#define LCD_EN DIO_PIN2

#define LCD_DATA_PORT DIO_PORTA

static void LCD_EnablePulse(void) {
    DIO_SetPinValue(DIO_PORTD, LCD_EN, DIO_PIN_HIGH);
    _delay_us(1);
    DIO_SetPinValue(DIO_PORTD, LCD_EN, DIO_PIN_LOW);
    _delay_us(100);
}

void LCD_Init(void) {
    _delay_ms(50);

    DIO_SetPinDirection(DIO_PORTD, LCD_RS, DIO_PIN_OUTPUT);
    DIO_SetPinDirection(DIO_PORTD, LCD_RW, DIO_PIN_OUTPUT);
    DIO_SetPinDirection(DIO_PORTD, LCD_EN, DIO_PIN_OUTPUT);
    
    DIO_SetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
    
    LCD_SendCommand(0x38);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x06);
    LCD_SendCommand(0x01);
    _delay_ms(2);
}

void LCD_SendCommand(uint8 command) {
    DIO_SetPinValue(DIO_PORTD, LCD_RS, DIO_PIN_LOW);
    DIO_SetPinValue(DIO_PORTD, LCD_RW, DIO_PIN_LOW);
    
    DIO_SetPortValue(LCD_DATA_PORT, command);
    LCD_EnablePulse();
}

void LCD_SendData(uint8 data) {
    DIO_SetPinValue(DIO_PORTD, LCD_RS, DIO_PIN_HIGH);
    DIO_SetPinValue(DIO_PORTD, LCD_RW, DIO_PIN_LOW);
    
    DIO_SetPortValue(LCD_DATA_PORT, data);
    LCD_EnablePulse();
}

void LCD_SendString(const char* str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}

void LCD_Clear(void) {
    LCD_SendCommand(0x01);
    _delay_ms(2);
}

void LCD_GoTo(uint8 row, uint8 col) {
    uint8 address;
    if (row == 0) {
        address = 0x80 + col;
    } else {
        address = 0xC0 + col;
    }
    LCD_SendCommand(address);
}

void LCD_DisplayNumber(uint32 number) {
    char buffer[11];
    uint8 i = 0;
    
    if (number == 0) {
        LCD_SendData('0');
        return;
    }
    
    while (number > 0) {
        buffer[i++] = (number % 10) + '0';
        number /= 10;
    }
    
    while (i > 0) {
        LCD_SendData(buffer[--i]);
    }
}