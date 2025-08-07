#ifndef SWITCHES_H
#define SWITCHES_H

#include <avr/io.h>
#include "gpio.h"

// تعريفات الأزرار
#define SWITCH_PORT   PORTC
#define SWITCH_DDR    DDRC
#define SWITCH_PIN    PINC

#define STOP_PIN      PC0
#define FORWARD_PIN   PC1
#define BACKWARD_PIN  PC2
#define LEFT_PIN      PC3
#define RIGHT_PIN     PC4

#define SWITCH_PRESSED     0
#define SWITCH_NOT_PRESSED 1

typedef struct {
    uint8_t stop;
    uint8_t forward;
    uint8_t backward;
    uint8_t left;
    uint8_t right;
} SwitchStates;

void SWITCH_Init(void);

SwitchStates SWITCH_GetStates(void);

#endif