#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"

void LCD_Init(void);
void LCD_SendCommand(uint8 command);
void LCD_SendData(uint8 data);
void LCD_SendString(const char* str);
void LCD_Clear(void);
void LCD_GoTo(uint8 row, uint8 col);
void LCD_DisplayNumber(uint32 number);

#endif