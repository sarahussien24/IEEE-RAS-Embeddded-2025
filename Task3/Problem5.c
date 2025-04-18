//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316084844

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int primary_sum = 0, secondary_sum = 0;
    for (int i = 0; i < N; i++) {
        primary_sum += matrix[i][i];
        secondary_sum += matrix[i][N - 1 - i];
    }

    int difference = abs(primary_sum - secondary_sum);
    printf("%d\n", difference);

    return 0;
}