#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>

#define LCD_PORT PORTD
#define LCD_DDR  DDRD
#define RS PD0
#define EN PD1

void LCD_Init(void);
void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_String(char *str);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);

#endif