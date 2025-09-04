#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/io.h>

void ULTRASONIC_Init(void);
uint16_t ULTRASONIC_ReadDistance(void);

#endif