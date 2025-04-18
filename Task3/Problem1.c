//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316079348

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    int X;
    scanf("%d", &X);
    
    int position = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            position = i;
            break;
        }
    }
    
    printf("%d\n", position);
    
    return 0;
}