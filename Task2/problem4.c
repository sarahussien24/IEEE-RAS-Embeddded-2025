//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312735911

#include <stdio.h>
 
void print_numbers(int n) {
    if (n == 0) return;
    print_numbers(n - 1);
    printf("%d\n", n);
}
 
int main() {
    int N;
    scanf("%d", &N);
    print_numbers(N);
    return 0;
}