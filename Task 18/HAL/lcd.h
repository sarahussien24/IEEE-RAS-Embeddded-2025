#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define LCD_PORT PORTC
#define LCD_DDR  DDRC

#define RS PC0
#define EN PC1

void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_Init(void);
void LCD_String(char *str);
void LCD_Clear(void);
void LCD_Number(uint16_t num);
#endif