#include <stdio.h>

int main() {
    // Declare and initialize variables
    int i = 10;
    float f = 0.5;
    char c = 'A';
    long l = 100000L;

    // Declare pointers
    int *ptr_i = &i;
    float *ptr_f = &f;
    char *ptr_c = &c;
    long *ptr_l = &l;

    // Display values and addresses using pointers
    printf("=== Integer ===\n");
    printf("Value of i: %d\n", i);
    printf("Address of i: %p\n", (void*)&i);
    printf("Accessed through pointer: %d\n", *ptr_i);
    printf("Pointer holds address: %p\n\n", (void*)ptr_i);

    printf("=== Character ===\n");
    printf("Value of c: %c\n", c);
    printf("Address of c: %p\n", (void*)&c);
    printf("Accessed through pointer: %c\n", *ptr_c);
    printf("Pointer holds address: %p\n\n", (void*)ptr_c);

    printf("=== Float ===\n");
    printf("Value of f: %.2f\n", f);
    printf("Address of f: %p\n", (void*)&f);
    printf("Accessed through pointer: %.2f\n", *ptr_f);
    printf("Pointer holds address: %p\n\n", (void*)ptr_f);

    printf("=== Long ===\n");
    printf("Value of l: %ld\n", l);
    printf("Address of l: %p\n", (void*)&l);
    printf("Accessed through pointer: %ld\n", *ptr_l);
    printf("Pointer holds address: %p\n", (void*)ptr_l);

    return 0;
}