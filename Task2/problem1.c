#include <stdio.h>

void is_divisible(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not allowed\n");
        return;
    }
    if (a % b == 0) {
        printf("%d is divisible by %d\n", a, b);
    } else {
        printf("%d is not divisible by %d\n", a, b);
    }
}

int main() {
    int a = 5, b = 10;
    is_divisible(a, b);
    return 0;
}
