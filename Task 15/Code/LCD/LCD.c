#include "LCD.h"

void LCD_Command(unsigned char cmnd) {
    LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
    LCD_Port &= ~(1 << RS);
    LCD_Port |= (1 << EN);
    _delay_ms(1);
    LCD_Port &= ~(1 << EN);
    _delay_ms(2);
    LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
    LCD_Port |= (1 << EN);
    _delay_ms(1);
    LCD_Port &= ~(1 << EN);
    _delay_ms(2);
}
void LCD_Char(unsigned char data) {
    LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
    LCD_Port |= (1 << RS);
    LCD_Port |= (1 << EN);
    _delay_ms(1);
    LCD_Port &= ~(1 << EN);
    _delay_ms(2);
    LCD_Port = (LCD_Port & 0x0F) | (data << 4);
    LCD_Port |= (1 << EN);
    _delay_ms(1);
    LCD_Port &= ~(1 << EN);
    _delay_ms(2);
}
void LCD_Init(void) {
    LCD_Dir |= 0xFF;
    _delay_ms(20);
    LCD_Command(0x02);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
    _delay_ms(2);
}
void LCD_String(char *str) {
    while (*str)
        LCD_Char(*str++);
}
void LCD_Clear() {
    LCD_Command(0x01);
    _delay_ms(2);
}
void LCD_SetCursor(unsigned char row, unsigned char col) {
    unsigned char pos[] = {0x80, 0xC0};
    LCD_Command(pos[row] + col);
}