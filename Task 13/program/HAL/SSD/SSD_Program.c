#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SSD_Interface.h"
#include "SSD_Private.h"
#include "SSD_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

int arrOfPins[10]={
0b11000000,
0b11111001,
0b10100100,
0b10110000,
0b10011001,
0b10010010,
0b10000010,
0b11111000,
0b10000000,
0b10010000 };
void SSD_voidInitSegmentPort ( u8 Copy_u8PortNumber ){

 if(Copy_u8PortNumber>PORTD ){

}else{
    switch(Copy_u8PortNumber){
       case PORTA : DIO_voidSetPortDirection(PORTA,OUTPUT);   break;
       case PORTB : DIO_voidSetPortDirection(PORTB,OUTPUT);   break;
       case PORTC : DIO_voidSetPortDirection(PORTC,OUTPUT);   break; 
       case PORTD : DIO_voidSetPortDirection(PORTD,OUTPUT);   break;   
    }  
 }
}

void SSD_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number ){

 if(Copy_u8PortNumber>PORTD ){

}else{

    switch(Copy_SegmentPolarity){

        case COMMON_ANODE : 
         switch(Copy_u8PortNumber){
            case PORTA: DIO_voidSetPortValue(PORTA,arrOfPins[Copy_u8Number]); break;
            case PORTB: DIO_voidSetPortValue(PORTB,arrOfPins[Copy_u8Number]); break;
            case PORTC: DIO_voidSetPortValue(PORTC,arrOfPins[Copy_u8Number]); break;
            case PORTD: DIO_voidSetPortValue(PORTD,arrOfPins[Copy_u8Number]); break;

            } break;
        case COMMON_CATHODE: 
        switch(Copy_u8PortNumber) {
            case PORTA: DIO_voidSetPortValue(PORTA,~arrOfPins[Copy_u8Number]); break;
            case PORTB: DIO_voidSetPortValue(PORTB,~arrOfPins[Copy_u8Number]); break;
            case PORTC: DIO_voidSetPortValue(PORTC,~arrOfPins[Copy_u8Number]); break;
            case PORTD: DIO_voidSetPortValue(PORTD,~arrOfPins[Copy_u8Number]); break; 
            } break;           
        }
      }
    }





