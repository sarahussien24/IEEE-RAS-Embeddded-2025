#include <stdio.h>

union storage {
    int a;
    float b;
    char c;
};

int main() {
    union storage data = {.a = 65};
    printf("Integer: %d\n", data.a);
    printf("Floated number: %f\n", data.b);
    printf("Character: %c\n", data.c);

    data.b = 100;
    printf("Integer: %d\n", data.a);
    printf("Floated number: %f\n", data.b);
    printf("Character: %c\n", data.c);

    data.c = 'S';
    printf("Integer: %d\n", data.a);
    printf("Floated number: %f\n", data.b);
    printf("Character: %c\n", data.c);
/*
 Since all union members share the same memory, changing one member's value
 affects how the others are interpreted, often resulting in unexpected outputs.
*/
}