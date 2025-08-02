#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

void LCD_voidInit (void){
DIO_voidSetPortDirection(LCD_DATA_PORT,OUTPUT);
DIO_voidSetPinDirection(LCD_CONTROL_PORT,RS_PIN,OUTPUT );
DIO_voidSetPinDirection(LCD_CONTROL_PORT,RW_PIN ,OUTPUT );
DIO_voidSetPinDirection(LCD_CONTROL_PORT,E_PIN  ,OUTPUT );
_delay_ms(35);

LCD_voidWriteCommand(FS_8BIT_2LINES_5x10);
_delay_ms(1);
LCD_voidWriteCommand(DIS_ON_YES_CURSER);
_delay_ms(1);
LCD_voidWriteCommand( DIS_CLEAR);
_delay_ms(1);
LCD_voidWriteCommand(ENTRY_MODE_INCREASE_NO_SHIFT );
_delay_ms(1);

}
void LCD_voidWriteCommand(u8 command){

DIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,LOW);
DIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,LOW);
DIO_voidSetPortValue(LCD_DATA_PORT,command);

DIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN  ,HIGH);
_delay_ms(1);
DIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN  ,LOW);

}
void  LCD_voidWriteChar ( u8 Copy_u8Char ){

DIO_voidSetPinValue(LCD_CONTROL_PORT,RS_PIN,LOW);
DIO_voidSetPinValue(LCD_CONTROL_PORT,RW_PIN,LOW);
DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Char);

DIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN  ,HIGH);
_delay_ms(1);
DIO_voidSetPinValue(LCD_CONTROL_PORT,E_PIN  ,LOW);

}

void LCD_voidWriteString (u8 *Copy_u8Arr ){
    u8 i=0;
    while(Copy_u8Arr[i] !='\0'){
        LCD_voidWriteChar(Copy_u8Arr[i]);
        i++;
    }

}
void LCD_voidDrawPattern ( u8 Copy_u8Pattern_Number , u8 *Copy_u8Arr_Pattern ){
LCD_voidWriteCommand(Copy_u8Pattern_Number);
for(int i=0;i<8;i++){
LCD_voidWriteChar(Copy_u8Arr_Pattern[i]);
 }
}

void LCD_voidWrite_u32Number ( u32 Copy_u32Number)
{

u8 arr[10];
u8 i=0;
while(Copy_u32Number>0){
arr[i]=Copy_u32Number%10;
Copy_u32Number /=10;
i++;
}
i--;
for(s16 k = i;k>=0;k++){
    LCD_voidWriteChar(arr[k]+'0');
}

}
void LCD_voidPosition ( u8 Copy_u8Line , u8 Copy_u8Position )
{
if(Copy_u8Line >LINE_2 || Copy_u8Position>15){

}else{

    switch(Copy_u8Line){
   case LINE_1:  LCD_voidWriteCommand(0x80+Copy_u8Position); break;
   case LINE_2:  LCD_voidWriteCommand(0xC0+Copy_u8Position); break;
    }
}
}