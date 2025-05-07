#include <stdio.h>
#include <stdlib.h>

int main() {
    int *m = malloc(3 * sizeof(int));
    int *c = calloc(3, sizeof(int));
    int *d;  // fourth block

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

    free(m);

    d = malloc(100 * sizeof(int));
    if (!d) {
        printf("Large allocation failed.\n");
        free(c);
        return 1;
    }

    for (int i = 0; i < 5; i++) d[i] = i + 100;
    printf("large malloc (after free): ");
    for (int i = 0; i < 5; i++) printf("%d ", d[i]);
    printf("...\n");

    free(c);
    free(d);
    return 0;
}