//https://codeforces.com/group/MWSDmqGsZm/contest/223205/submission/312734221

#include <stdio.h>
#include <string.h>
 
int is_odd(int num) {
    return num % 2 != 0;
}
 
int is_binary_palindrome(int num) {
    char binary[32];
    int index = 0;
    
    while (num > 0) {
        binary[index++] = (num % 2) + '0';
        num /= 2;
    }
    binary[index] = '\0';
    
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        if (binary[i] != binary[j]) {
            return 0;
        }
    }
    return 1;
}
 
int main() {
    int N;
    scanf("%d", &N);
    
    if (is_odd(N) && is_binary_palindrome(N)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}