//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312735426

#include <stdio.h>
 
int sequence_length(long long n) {
    if (n == 1) return 1;  
    if (n % 2 == 0) 
        return 1 + sequence_length(n / 2);
    else 
        return 1 + sequence_length(3 * n + 1);
}
 
int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d\n", sequence_length(n));
    return 0;
}