#include <stdio.h>

// Function to convert string to positive integer
int stringToPositiveInt(const char *str) {
    int result = 0;
    
    while (*str == ' ') str++;
    if (*str == '-') {
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert characters to integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result;  // returns positive integer
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    int number = stringToPositiveInt(input);
    printf("Converted value is: %d\n", number);

    return 0;
}
