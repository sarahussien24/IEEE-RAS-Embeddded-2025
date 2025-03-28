#include <stdio.h>
#include <math.h>

int is_armstrong(int num) {
    int originalNum, remainder, n = 0;
    double result = 0.0;

    originalNum = num;
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    return (int)result == num;
}

void print_armstrong_numbers(int lower, int upper) {
    printf("Armstrong numbers between %d and %d are: ", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (is_armstrong(i)) {
            printf("%d, ", i);
        }
    }
    printf("\b\b \n");
}

int main() {
    int lower, upper;
    printf("Enter the lower limit: ");
    scanf("%d", &lower);
    printf("Enter the upper limit: ");
    scanf("%d", &upper);
    print_armstrong_numbers(lower, upper);
    return 0;
}