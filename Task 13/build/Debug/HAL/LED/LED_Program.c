#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

void LED_voidInit_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber ){
if(Copy_u8PortNumber>PORTD || Copy_u8PinNumber>PIN7){

}else{

    DIO_voidSetPinDirection(Copy_u8PortNumber,Copy_u8PinNumber,OUTPUT);
 }
}
void LED_voidStatus_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status ){
 if(Copy_u8PortNumber>PORTD || Copy_u8PinNumber>PIN7){

}else{
switch(Copy_u8Status){
     case ON : DIO_voidSetPinValue(Copy_u8PortNumber,Copy_u8PinNumber,HIGH);   break;
     case OFF : DIO_voidSetPinValue(Copy_u8PortNumber,Copy_u8PinNumber,LOW);   break;
  }
 }
}
void LED_voidToggle_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber ){

 if(Copy_u8PortNumber>PORTD || Copy_u8PinNumber>PIN7){

}else{

  DIO_voidTogglePinValue(Copy_u8PortNumber,Copy_u8PinNumber);

}
}