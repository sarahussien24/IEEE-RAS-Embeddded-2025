#include <stdio.h>

// Function to return the length
int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[100]; 

    // input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Call the function and print
    int len = stringLength(str);
    printf("Length = %d\n", len);

    return 0;
}
