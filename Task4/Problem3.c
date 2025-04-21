#include <stdio.h>

// Function to swap
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    int a, b;
    // input from user
    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("\nBefore swap: a = %d, b = %d\n", a, b);

    // Call swap function
    swap(&a, &b);

    // Display after swap
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}
