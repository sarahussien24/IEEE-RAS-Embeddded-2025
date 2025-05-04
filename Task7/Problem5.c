#include <stdio.h>

typedef enum {
    Add = '+',
    Subtract = '-',
    Multiply = '*',
    Divide = '/',
    AND = '&',
    OR = '|',
    NOT = '!',
} operation;

// Evaluation function
int evaluate(operation op, int a, int b) {
    switch (op) {
        case Add:
            return a + b;
        case Subtract:
            return a - b;
        case Multiply:
            return a * b;
        case Divide:
            if (b != 0)
                return a / b;
            else {
                printf("Error Division by zero.\n");
                return 0;
            }
        case AND:
            return a & b;
        case OR:
            return a | b;
        case NOT:
            return ~a;
        default:
            printf("Invalid operation.\n");
            return 0;
    }
}

int main() {
    int a, b = 0;
    char op;

    printf("Input first number: ");
    scanf("%d", &a);

    printf("Input operation (+, -, *, /, &, |, !): ");
    scanf(" %c", &op); 

    if (op != '!') {
        printf("Input second number: ");
        scanf("%d", &b);
    }

    int result = evaluate((operation)op, a, b);

    if (op == '!') {
        printf("%c%d = %d\n", op, a, result);
    } else {
        printf("%d %c %d = %d\n", a, op, b, result);
    }

    return 0;

/*
  Size of the enum Operation:
  The size of the enum will depend on the underlying data type used to store the enum values. the default underlying type for enums is usually 'int'.
  Typically, the size of an 'int' is 4 bytes on most platforms.
  So, the size of enum Operation is usually 4 bytes.

  If we add extra members to the enum:
  - If the new members still fit within the range of an 'int', the size of the enum will remain 4 bytes.
  - However, if the values of the enum exceed the range of an 'int', the compiler might choose a larger data type, in which case the size of the enum might increase to 8 bytes .
*/
}