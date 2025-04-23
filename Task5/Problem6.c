#include <stdio.h>

// Arithmetic operations
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int choice, a, b;
    int (*operation)(int, int);

    printf("Select an operation:\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    //select operation
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        case 4:
            operation = divide;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    // print result
    int result = operation(a, b);
    printf("Result: %d\n", result);

    return 0;
}