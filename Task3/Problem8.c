//https://codeforces.com/group/MWSDmqGsZm/contest/219856/submission/316088420

#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int in_word = 0, count = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    printf("%d\n", count);
    return 0;
}
