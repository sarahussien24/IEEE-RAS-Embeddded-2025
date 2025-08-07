#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "motor.h"
#include "switches.h"
#include <string.h>

#define DEBOUNCE_DELAY_MS 50

int main(void) {
    SWITCH_Init();
    Motor_Init();
    
    SwitchStates currentState, previousState;
    previousState = SWITCH_GetStates();
    
    while(1) {
        currentState = SWITCH_GetStates();
        if (currentState.stop == SWITCH_PRESSED) {
            Motor_StopAll();
        }
        else if (currentState.forward == SWITCH_PRESSED) {
            Motor_MoveForward();
        }
        else if (currentState.backward == SWITCH_PRESSED) {
            Motor_MoveBackward();
        }
        else if (currentState.left == SWITCH_PRESSED) {
            Motor_TurnLeft();
        }
        else if (currentState.right == SWITCH_PRESSED) {
            Motor_TurnRight();
        }
        else {
            Motor_StopAll();
        }
        
        previousState = currentState;
        _delay_ms(50);
    }
}