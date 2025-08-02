#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_voidInit_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
void LED_voidStatus_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status );
void LED_voidToggle_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
#endif