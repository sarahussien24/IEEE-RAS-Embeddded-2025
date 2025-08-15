#include "LCD/LCD.h"
#include "KEYPAD/KEYPAD.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int apply_op(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        default: return 0;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int evaluate(char* expr) {
    int values[20];
    char ops[20];
    int valTop = -1, opTop = -1;
    int i = 0;

    while (expr[i]) {
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            values[++valTop] = num;
        } else if (strchr("+-*/", expr[i])) {
            while (opTop >= 0 && precedence(ops[opTop]) >= precedence(expr[i])) {
                int b = values[valTop--];
                int a = values[valTop--];
                char op = ops[opTop--];
                values[++valTop] = apply_op(a, b, op);
            }
            ops[++opTop] = expr[i++];
        } else {
            i++;
        }
    }

    while (opTop >= 0) {
        int b = values[valTop--];
        int a = values[valTop--];
        char op = ops[opTop--];
        values[++valTop] = apply_op(a, b, op);
    }

    return values[valTop];
}

int main(void) {
    LCD_Init();
    KEYPAD_PORT = 0xFF;

    LCD_Clear();
    LCD_SetCursor(0, 3);
    LCD_String("Sara ^_^");
    LCD_SetCursor(1, 1);
    LCD_String("     ------Calculation------");
    _delay_ms(2000);
    LCD_Clear();

    char expr[33] = "";
    uint8_t pos = 0;

    LCD_String("Calc: ");

    while (1) {
        char key = KEYPAD_4x4_GetKey();

        if ((key >= '0' && key <= '9') || strchr("+-*/", key)) {
            if (pos < 31) {
                expr[pos++] = key;
                expr[pos] = '\0';
                LCD_Char(key);
            }
        } else if (key == '=') {
            int result = evaluate(expr);
            char res_str[10];
            itoa(result, res_str, 10);
            LCD_Clear();
            LCD_SetCursor(0, 0);
            LCD_String(expr);
            LCD_Char('=');
            LCD_String(res_str);
            pos = 0;
            expr[0] = '\0';
        } else if (key == 'C') {
            LCD_Clear();
            LCD_SetCursor(0, 0);
            LCD_String("Calc: ");
            pos = 0;
            expr[0] = '\0';
        }
    }
}