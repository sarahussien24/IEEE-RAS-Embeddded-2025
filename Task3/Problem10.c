#include <stdio.h>
#define MAX 100

int main() {
    int n, i, j;
    int square[MAX][MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &square[i][j]);

    int magic = 1;

    int seen[MAX * MAX] = {0};
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int val = square[i][j];
            if (val < 1 || val > n * n || seen[val]) {
                magic = 0;
                break;
            }
            seen[val] = 1;
        }
        if (!magic) break;
    }

    if (magic) {
        int sum = 0;
        for (j = 0; j < n; j++)
            sum += square[0][j];

        for (i = 1; i < n; i++) {
            int row_sum = 0;
            for (j = 0; j < n; j++)
                row_sum += square[i][j];
            if (row_sum != sum) {
                magic = 0;
                break;
            }
        }

        if (magic) {
            for (j = 0; j < n; j++) {
                int col_sum = 0;
                for (i = 0; i < n; i++)
                    col_sum += square[i][j];
                if (col_sum != sum) {
                    magic = 0;
                    break;
                }
            }
        }

        if (magic) {
            int diag1_sum = 0;
            for (i = 0; i < n; i++)
                diag1_sum += square[i][i];
            if (diag1_sum != sum)
                magic = 0;
        }

        if (magic) {
            int diag2_sum = 0;
            for (i = 0; i < n; i++)
                diag2_sum += square[i][n - 1 - i];
            if (diag2_sum != sum)
                magic = 0;
        }
    }

    if (magic=1)
        printf("The square is a magic square.\n");
    else
        printf("The square is not a magic square.\n");
    return 0;
}
