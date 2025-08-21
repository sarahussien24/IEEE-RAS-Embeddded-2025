#include "EXTI1.h"
#include "EXTI1_REGISTER.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>

static void (*EXTI1_CallBack)(void) = NULL;

void EXTI1_Init(EXTI1_SenseControl_t senseControl) {
    switch(senseControl) {
        case EXTI1_LOW_LEVEL:
            CLR_BIT(MCUCR, ISC10);
            CLR_BIT(MCUCR, ISC11);
            break;
        case EXTI1_LOGIC_CHANGE:
            SET_BIT(MCUCR, ISC10);
            CLR_BIT(MCUCR, ISC11);
            break;
        case EXTI1_FALLING_EDGE:
            CLR_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
        case EXTI1_RISING_EDGE:
            SET_BIT(MCUCR, ISC10);
            SET_BIT(MCUCR, ISC11);
            break;
    }
}

void EXTI1_Enable(void) {
    SET_BIT(GICR, INT1);
}

void EXTI1_Disable(void) {
    CLR_BIT(GICR, INT1);
}

void EXTI1_SetCallBack(void (*ptr)(void)) {
    EXTI1_CallBack = ptr;
}

ISR(INT1_vect) {
    if (EXTI1_CallBack != NULL) {
        EXTI1_CallBack();
    }
}