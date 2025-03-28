//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312735830

#include <stdio.h>
 
int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
 
int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", fibonacci(N));
    return 0;
}