#include "EXTI0.h"
#include "EXTI0_REGISTER.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>

static void (*EXTI0_CallBack)(void) = NULL;

void EXTI0_Init(EXTI0_SenseControl_t senseControl) {
    switch(senseControl) {
        case EXTI0_LOW_LEVEL:
            CLR_BIT(MCUCR, ISC00);
            CLR_BIT(MCUCR, ISC01);
            break;
        case EXTI0_LOGIC_CHANGE:
            SET_BIT(MCUCR, ISC00);
            CLR_BIT(MCUCR, ISC01);
            break;
        case EXTI0_FALLING_EDGE:
            CLR_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
        case EXTI0_RISING_EDGE:
            SET_BIT(MCUCR, ISC00);
            SET_BIT(MCUCR, ISC01);
            break;
    }
}

void EXTI0_Enable(void) {
    SET_BIT(GICR, INT0);
}

void EXTI0_Disable(void) {
    CLR_BIT(GICR, INT0);
}

void EXTI0_SetCallBack(void (*ptr)(void)) {
    EXTI0_CallBack = ptr;
}

ISR(INT0_vect) {
    if (EXTI0_CallBack != NULL) {
        EXTI0_CallBack();
    }
}