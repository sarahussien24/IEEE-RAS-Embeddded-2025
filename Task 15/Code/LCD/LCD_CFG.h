#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Dir    DDRC
#define LCD_Port   PORTC
#define RS         PC0
#define EN         PC2

#endif