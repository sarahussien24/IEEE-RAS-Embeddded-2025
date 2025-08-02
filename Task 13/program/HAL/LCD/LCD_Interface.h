#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define    LINE_1               0
#define    LINE_2               1

#define    PATTERN_0        0b01000000
#define    PATTERN_1        0b01001000         
#define    PATTERN_2        0b01010000 
#define    PATTERN_3        0b01011000
#define    PATTERN_4        0b01100000
#define    PATTERN_5        0b01101000
#define    PATTERN_6        0b01110000
#define    PATTERN_7        0b01111000

void LCD_voidInit (void);
void LCD_voidWriteCommand ( u8 Copy_u8Command );
void LCD_voidWriteChar ( u8 Copy_u8Char );
void LCD_voidWriteString (u8 *Copy_u8Arr );
void LCD_voidDrawPattern ( u8 Copy_u8Pattern_Number , u8 *Copy_u8Arr_Pattern );
void LCD_voidWrite_u32Number ( u32 Copy_u32Number);
void LCD_voidPosition ( u8 Copy_u8Line , u8 Copy_u8Position );
#endif