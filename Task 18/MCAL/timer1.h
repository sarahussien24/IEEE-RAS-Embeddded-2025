#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>

void TIMER1_Init(void);
uint16_t TIMER1_InputCapture(void);

#endif