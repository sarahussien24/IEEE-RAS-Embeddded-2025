#include <stdio.h>

int isPerfect(int num) {
    if (num < 2) return 0;
    int sum = 0, i = 1;
    while (i <= num / 2) {
        if (num % i == 0)
            sum += i;
        i++;
    }
    return sum == num;
}

int main() {
    int num;
    printf("Enter a positive number: ");
    scanf("%d", &num);
    
    if (num <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }
    
    if (isPerfect(num))
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);
    
    return 0;
}
