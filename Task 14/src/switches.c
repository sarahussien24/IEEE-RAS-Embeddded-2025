#include "switches.h"

void SWITCH_Init(void) {
    SWITCH_DDR &= ~((1<<STOP_PIN)|(1<<FORWARD_PIN)|(1<<BACKWARD_PIN)|(1<<LEFT_PIN)|(1<<RIGHT_PIN));
    SWITCH_PORT |= ((1<<STOP_PIN)|(1<<FORWARD_PIN)|(1<<BACKWARD_PIN)|(1<<LEFT_PIN)|(1<<RIGHT_PIN));
}

SwitchStates SWITCH_GetStates(void) {
    SwitchStates states;
    
    states.stop = GPIO_ReadPin(&SWITCH_PIN, STOP_PIN);
    states.forward = GPIO_ReadPin(&SWITCH_PIN, FORWARD_PIN);
    states.backward = GPIO_ReadPin(&SWITCH_PIN, BACKWARD_PIN);
    states.left = GPIO_ReadPin(&SWITCH_PIN, LEFT_PIN);
    states.right = GPIO_ReadPin(&SWITCH_PIN, RIGHT_PIN);
    
    return states;
}