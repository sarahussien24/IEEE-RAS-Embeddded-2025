#include "KEYPAD.h"
#include <util/delay.h>

char KEYPAD_4x4_GetKey() {
    KEYPAD_PORT_DIR = 0xF0;
    KEYPAD_PORT = 0xFF;

    char keymap[4][4] = {
        {'7', '8', '9', '/'},
        {'4', '5', '6', '*'},
        {'1', '2', '3', '-'},
        {'C', '0', '=', '+'}
    };

    while (1) {
        for (int row = 0; row < 4; row++) {
            KEYPAD_PORT = ~(1 << (row + 4));
            for (int col = 0; col < 4; col++) {
                if (!(KEYPAD_PIN & (1 << col))) {
                    _delay_ms(200);
                    return keymap[row][col];
                }
            }
        }
    }
}