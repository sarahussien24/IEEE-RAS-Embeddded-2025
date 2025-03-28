//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312735974

#include <stdio.h>
 
int can_reach(long long current, long long target) {
    if (current > target) return 0;
    if (current == target) return 1;
    return can_reach(current * 10, target) || can_reach(current * 20, target);
}
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long N;
        scanf("%lld", &N);
        if (can_reach(1, N))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}