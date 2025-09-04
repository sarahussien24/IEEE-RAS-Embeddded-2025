#include "lcd.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define LCD_PORT PORTC
#define RS PC0
#define EN PC1

void LCD_Command(uint8_t cmnd)
{
    LCD_PORT = (LCD_PORT & 0x0F) | (cmnd & 0xF0);
    LCD_PORT &= ~(1 << RS);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_us(200);

    LCD_PORT = (LCD_PORT & 0x0F) | (cmnd << 4);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_Char(unsigned char data)
{
    LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
    LCD_PORT |= (1 << RS);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);

    LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
    LCD_PORT |= (1 << EN);
    _delay_us(1);
    LCD_PORT &= ~(1 << EN);
    _delay_ms(2);
}

void LCD_Init(void)
{
    DDRC = 0xFF;
    _delay_ms(20);
    LCD_Command(0x02);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
}

void LCD_String(char *str)
{
    while (*str) LCD_Char(*str++);
}

void LCD_Clear(void)
{
    LCD_Command(0x01);
    _delay_ms(2);
}

void LCD_Number(uint16_t num)
{
    char buffer[10];
    uint8_t i = 0;

    if (num == 0) {
        LCD_Char('0');
        return;
    }

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0) {
        LCD_Char(buffer[--i]);
    }
}