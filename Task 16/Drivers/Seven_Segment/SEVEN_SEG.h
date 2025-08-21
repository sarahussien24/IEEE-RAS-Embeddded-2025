#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "../DIO/DIO.h"

#define SEGMENT_A DIO_PIN0
#define SEGMENT_B DIO_PIN1
#define SEGMENT_C DIO_PIN2
#define SEGMENT_D DIO_PIN3
#define SEGMENT_E DIO_PIN4
#define SEGMENT_F DIO_PIN5
#define SEGMENT_G DIO_PIN6
#define SEGMENT_DP DIO_PIN7

void SEVEN_SEG_Init(void);
void SEVEN_SEG_DisplayNumber(uint8 number);
void SEVEN_SEG_DisplayPattern(uint8 pattern);

#endif