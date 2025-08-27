#include "lcd.h"

void LCD_Command(unsigned char cmnd) {
    LCD_PORT = (LCD_PORT & 0x0F) | (cmnd & 0xF0);
    LCD_PORT &= ~(1<<RS);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_us(200);

    LCD_PORT = (LCD_PORT & 0x0F) | (cmnd<<4);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(2);
}

void LCD_Char(unsigned char data) {
    LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
    LCD_PORT |= (1<<RS);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);

    LCD_PORT = (LCD_PORT & 0x0F) | (data<<4);
    LCD_PORT |= (1<<EN);
    _delay_us(1);
    LCD_PORT &= ~(1<<EN);
    _delay_ms(2);
}

void LCD_Init(void) {
    LCD_DDR = 0xFF;
    _delay_ms(20);

    LCD_Command(0x02);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
}

void LCD_String(char *str) {
    while(*str) LCD_Char(*str++);
}

void LCD_Clear(void) {
    LCD_Command(0x01);
    _delay_ms(2);
}

void LCD_SetCursor(uint8_t row, uint8_t col) {
    if(row == 0) LCD_Command(0x80 + col);
    else LCD_Command(0xC0 + col);
}