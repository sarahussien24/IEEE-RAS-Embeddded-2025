#ifndef LCD_H_
#define LCD_H_

#include "LCD_CFG.h"

void LCD_Init(void);
void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_String(char *str);
void LCD_Clear();
void LCD_SetCursor(unsigned char row, unsigned char col);

#endif