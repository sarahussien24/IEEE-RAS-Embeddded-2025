#ifndef EXTI1_H_
#define EXTI1_H_

#include "STD_TYPES.h"

typedef enum {
    EXTI1_LOW_LEVEL,
    EXTI1_LOGIC_CHANGE,
    EXTI1_FALLING_EDGE,
    EXTI1_RISING_EDGE
} EXTI1_SenseControl_t;

void EXTI1_Init(EXTI1_SenseControl_t senseControl);
void EXTI1_Enable(void);
void EXTI1_Disable(void);
void EXTI1_SetCallBack(void (*ptr)(void));

#endif