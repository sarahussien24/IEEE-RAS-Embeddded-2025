#include "SEVEN_SEG.h"
#include "../DIO/DIO.h"

static const uint8 seven_seg_patterns[10] = {
    0b00111111, // 0 - A,B,C,D,E,F
    0b00000110, // 1 - B,C
    0b01011011, // 2 - A,B,D,E,G
    0b01001111, // 3 - A,B,C,D,G
    0b01100110, // 4 - B,C,F,G
    0b01101101, // 5 - A,C,D,F,G
    0b01111101, // 6 - A,C,D,E,F,G
    0b00000111, // 7 - A,B,C
    0b01111111, // 8 - A,B,C,D,E,F,G
    0b01101111  // 9 - A,B,C,D,F,G
};

void SEVEN_SEG_Init(void) {
    DIO_SetPortDirection(DIO_PORTB, DIO_PORT_OUTPUT);

    DIO_SetPortValue(DIO_PORTB, 0x00);
}

void SEVEN_SEG_DisplayNumber(uint8 number) {
    if (number <= 9) {
        SEVEN_SEG_DisplayPattern(seven_seg_patterns[number]);
    } else {
        SEVEN_SEG_DisplayPattern(0b01000000);
    }
}

void SEVEN_SEG_DisplayPattern(uint8 pattern) {
    DIO_SetPortValue(DIO_PORTB, pattern);
}