#include <stdio.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    int sum = sumOfDigits(num);
    if (isPrime(sum))
        printf("The sum of digits (%d) is a prime number.\n", sum);
    else
        printf("The sum of digits (%d) is not a prime number.\n", sum);
    
    return 0;
}