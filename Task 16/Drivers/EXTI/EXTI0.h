#ifndef EXTI0_H_
#define EXTI0_H_

#include "../Libraries/STD_TYPES.h"

typedef enum {
    EXTI0_LOW_LEVEL,
    EXTI0_LOGIC_CHANGE,
    EXTI0_FALLING_EDGE,
    EXTI0_RISING_EDGE
} EXTI0_SenseControl_t;

void EXTI0_Init(EXTI0_SenseControl_t senseControl);
void EXTI0_Enable(void);
void EXTI0_SetCallBack(void (*ptr)(void));

#endif