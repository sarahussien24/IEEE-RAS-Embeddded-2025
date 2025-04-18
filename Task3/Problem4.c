#include <stdio.h>
#include <string.h>

#define SIZE 3

int main() {
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], sum[SIZE][SIZE];
    char label[20];
    int i, j;

    scanf("%s", label);

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &matrix1[i][j]);

    scanf("%s", label);

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            scanf("%d", &matrix2[i][j]);

    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            sum[i][j] = matrix1[i][j] + matrix2[i][j];

    printf("Sum of both matrix =\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}