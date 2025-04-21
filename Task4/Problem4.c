#include <stdio.h>

// Function to print even numbers
void printEvenNumbers(char *str) {
    while (*str) {
        if ((*str - '0') % 2 == 0) { 
            printf("%c", *str);
        }
        str++;
    }
    printf("\n");
}

int main() {
    char str[100];

    //input from the user
    printf("Enter a string of numbers: ");
    scanf("%s", str);

    printf("Even numbers in the string: ");
    printEvenNumbers(str);

    return 0;
}