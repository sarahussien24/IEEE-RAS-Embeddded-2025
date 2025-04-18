//http://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316085181

#include <stdio.h>
 
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
 
    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][M - 1 - j];
            matrix[i][M - 1 - j] = temp;
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}