#include <stdio.h>

//to switch uncomment and comment
// #define ADD_OPERATION
#define SUB_OPERATION

#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))

int main() {
    int a, b, result;

    printf("Enter two integers:\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

#ifdef ADD_OPERATION
    result = ADD(a, b);
    printf("Result (Addition): %d\n", result);
#elif defined(SUB_OPERATION)
    result = SUB(a, b);
    printf("Result (Subtraction): %d\n", result);
#else
    printf("No operation macro defined.\n");
#endif

    return 0;
}