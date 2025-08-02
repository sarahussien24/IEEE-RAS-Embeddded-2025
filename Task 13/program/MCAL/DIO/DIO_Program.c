#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


void DIO_voidSetPinDirection (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Direction ){
if(Copy_u8PortNumber > PORTD || Copy_u8PinNumber>PIN7 ){

}else{
switch(Copy_u8Direction ){
case INPUT: switch(Copy_u8PortNumber){
            case PORTA: CLEAR_BIT(DDRA_REG ,Copy_u8PinNumber); break;
            case PORTB: CLEAR_BIT(DDRB_REG ,Copy_u8PinNumber); break;
            case PORTC: CLEAR_BIT(DDRC_REG ,Copy_u8PinNumber); break;
            case PORTD: CLEAR_BIT(DDRD_REG ,Copy_u8PinNumber); break;

            } break;
case OUTPUT: switch(Copy_u8PortNumber ) {

            case PORTA: SET_BIT(DDRA_REG ,Copy_u8PinNumber); break;
            case PORTB: SET_BIT(DDRB_REG ,Copy_u8PinNumber); break;
            case PORTC: SET_BIT(DDRC_REG ,Copy_u8PinNumber); break;
            case PORTD: SET_BIT(DDRD_REG ,Copy_u8PinNumber); break; 
            } break;           
        }
   }
}
 void DIO_voidSetPortDirection (u8 Copy_u8PortNumber, u8 Copy_u8Direction ){


if(Copy_u8PortNumber > PORTD  ){

} 
else{
switch(Copy_u8Direction ){
case INPUT: switch(Copy_u8PortNumber){
            case PORTA:   DDRA_REG=0x00;               break;
            case PORTB:   DDRB_REG=0x00;               break;
            case PORTC:   DDRC_REG=0x00;               break;
            case PORTD:   DDRD_REG=0x00;               break;

            } break;
case OUTPUT: switch(Copy_u8PortNumber ) {

            case PORTA:   DDRA_REG=0xff;               break;
            case PORTB:   DDRB_REG=0xff;               break;
            case PORTC:   DDRC_REG=0xff;               break;
            case PORTD:   DDRD_REG=0xff;               break;
            } break;           
        }
   }   
 }
 void DIO_voidSetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Value ){

 if(Copy_u8PortNumber > PORTD || Copy_u8PinNumber>PIN7 ){

}else{
switch(Copy_u8Value ){
case LOW: switch(Copy_u8PortNumber){
            case PORTA: CLEAR_BIT(PORTA_REG ,Copy_u8PinNumber); break;
            case PORTB: CLEAR_BIT(PORTB_REG ,Copy_u8PinNumber); break;
            case PORTC: CLEAR_BIT(PORTC_REG ,Copy_u8PinNumber); break;
            case PORTD: CLEAR_BIT(PORTD_REG ,Copy_u8PinNumber); break;

            } break;
case HIGH: switch(Copy_u8PortNumber ) {

            case PORTA: SET_BIT(PORTA_REG ,Copy_u8PinNumber); break;
            case PORTB: SET_BIT(PORTB_REG ,Copy_u8PinNumber); break;
            case PORTC: SET_BIT(PORTC_REG ,Copy_u8PinNumber); break;
            case PORTD: SET_BIT(PORTD_REG ,Copy_u8PinNumber); break; 
            } break;           
        }
   }
}
 void DIO_voidSetPortValue (u8 Copy_u8PortNumber, u8 Copy_u8Value ){

if(Copy_u8PortNumber > PORTD  ){

} 
else{
 switch(Copy_u8PortNumber){
            case PORTA:   PORTA_REG=Copy_u8Value;               break;
            case PORTB:   PORTB_REG=Copy_u8Value;               break;
            case PORTC:   PORTC_REG=Copy_u8Value;               break;
            case PORTD:   PORTD_REG=Copy_u8Value;               break;
  
   }   
 }
}


u8 DIO_u8GetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber ){
u8 Local_u8Variable;
if(Copy_u8PortNumber > PORTD || Copy_u8PinNumber>PIN7 ){

}else{
switch(Copy_u8PortNumber) {

            case PORTA:   Local_u8Variable = GET_BIT(PINA_REG ,Copy_u8PinNumber); break;
            case PORTB:   Local_u8Variable = GET_BIT(PINB_REG ,Copy_u8PinNumber); break;
            case PORTC:   Local_u8Variable = GET_BIT(PINC_REG ,Copy_u8PinNumber); break;
            case PORTD:   Local_u8Variable = GET_BIT(PIND_REG ,Copy_u8PinNumber); break; 
            }           
        }
return Local_u8Variable ;
}

u8 DIO_u8GetPortValue (u8 Copy_u8PortNumber ){
 u8 Local_u8Variable;
if(Copy_u8PortNumber > PORTD  ){

}else{
switch(Copy_u8PortNumber ) {

            case PORTA:   Local_u8Variable = PINA_REG  ; break;
            case PORTB:   Local_u8Variable = PINB_REG  ; break;
            case PORTC:   Local_u8Variable = PINC_REG  ; break;
            case PORTD:   Local_u8Variable = PIND_REG  ; break; 
            }           
        }
return Local_u8Variable ;

}
void DIO_voidTogglePinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber ){
if(Copy_u8PortNumber > PORTD || Copy_u8PinNumber>PIN7 ){

}else{
 switch(Copy_u8PortNumber){
            case PORTA: TOGGLE_BIT(PORTA_REG ,Copy_u8PinNumber); break;
            case PORTB: TOGGLE_BIT(PORTB_REG ,Copy_u8PinNumber); break;
            case PORTC: TOGGLE_BIT(PORTC_REG ,Copy_u8PinNumber); break;
            case PORTD: TOGGLE_BIT(PORTD_REG ,Copy_u8PinNumber); break;

            } 

}
}
void DIO_voidTogglePortValue (u8 Copy_u8PortNumber ){
    if(Copy_u8PortNumber > PORTD  ){

}else{
 switch(Copy_u8PortNumber){

            case PORTA:   PORTA_REG ^=0xff;               break;
            case PORTB:   PORTB_REG ^=0xff;               break;
            case PORTC:   PORTC_REG ^=0xff;               break;
            case PORTD:   PORTD_REG ^=0xff;               break;
            } 
        }
    }


void DIO_voidConfig_Pull_Up_Pin (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PullUpStatus){

if(Copy_u8PortNumber > PORTD || Copy_u8PinNumber>PIN7 ){

}else{
 switch(Copy_u8PullUpStatus){
            case ON: DIO_voidSetPinValue( Copy_u8PortNumber,Copy_u8PinNumber,HIGH); break;
            case OFF: DIO_voidSetPinValue( Copy_u8PortNumber,Copy_u8PinNumber,LOW); break;
    }
}
}
void DIO_voidConfig_Pull_Up_Port (u8 Copy_u8PortNumber, u8 Copy_u8PullUpStatus ){

    if(Copy_u8PortNumber > PORTD  ){

}else{
 switch(Copy_u8PullUpStatus){
            case ON:  DIO_voidSetPortValue( Copy_u8PortNumber,HIGH); break;
            case OFF: DIO_voidSetPortValue( Copy_u8PortNumber,LOW);  break;
    }
}
}