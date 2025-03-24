#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}

int main() {
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
    
    if (isPalindrome(word))
        printf("The word '%s' is a palindrome.\n", word);
    else
        printf("The word '%s' is not a palindrome.\n", word);
    
    return 0;
}