//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316080175

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    int min_val = A[0];
    int min_pos = 1;
    
    for (int i = 1; i < N; i++) {
        if (A[i] < min_val) {
            min_val = A[i];
            min_pos = i + 1;
        }
    }
    
    printf("%d %d\n", min_val, min_pos);
    
    return 0;
}