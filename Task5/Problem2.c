#include <stdio.h>
#define MAX_LENGTH 100

void stringCopy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char original[MAX_LENGTH];
    char copied[MAX_LENGTH];
    
    printf("Enter a string: ");
    
    // Read input
    char *ptr = original;
    char ch;
    while ((ch = getchar()) != '\n' && ptr < original + MAX_LENGTH - 1) {
        *ptr++ = ch;
    }
    *ptr = '\0'; 
    
    stringCopy(copied, original);
    
    printf("Original String: %s\n", original);
    printf("Copied String: %s\n", copied);
    
    return 0;
}
