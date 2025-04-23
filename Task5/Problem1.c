#include <stdio.h>
#define MAX_SIZE 100

// Function to compare two strings
int compareStrings(char *a, char *b) {
    while (*a && *b) {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];

    printf("Enter first string: ");
    fgets(str1, MAX_SIZE, stdin);

    printf("Enter second string: ");
    fgets(str2, MAX_SIZE, stdin);

    // Remove trailing newline if present
    for (char *p = str1; *p; p++) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }

    for (char *p = str2; *p; p++) {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
    }

    if (compareStrings(str1, str2))
        printf("Both strings are Identical\n");
    else
        printf("Strings are NOT Identical\n");

    return 0;
}
