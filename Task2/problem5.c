//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312734944

#include <stdio.h>
 
void print_digits(long long n) {
    if (n < 10) {
        printf("%lld", n);
        return;
    }
    print_digits(n / 10);
    printf(" %lld", n % 10);
}
 
int main() {
    int T;
    long long N;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        print_digits(N);
        printf("\n");
    }
    return 0;
}