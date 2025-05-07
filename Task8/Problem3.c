#include <stdio.h>

int main() {
    int *m = malloc(3 * sizeof(int));
    int *c = calloc(3, sizeof(int));
    int *r;
    
    if (!m || !c) {
        printf("Initial allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) m[i] = i + 1;
    printf("malloc: ");
    for (int i = 0; i < 3; i++) printf("%d ", m[i]);
    printf("\n");

    printf("calloc: ");
    for (int i = 0; i < 3; i++) printf("%d ", c[i]);
    printf("\n");

    r = realloc(m, 5 * sizeof(int));
    if (!r) {
        printf("realloc failed.\n");
        free(m);
        free(c);
        return 1;
    }
    for (int i = 3; i < 5; i++) r[i] = (i + 1) * 10;

    printf("realloc (malloc → bigger): ");
    for (int i = 0; i < 5; i++) printf("%d ", r[i]);
    printf("\n");

    free(r);
    free(c);
    return 0;
}