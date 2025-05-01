#include <stdio.h>

struct Animal {
    char type[20];     // 20 bytes
    char name[50];     // 50 bytes
    int age;           // 4 bytes
    char kind[60];     // 60 bytes
};

int main() {
    struct Animal dog;

    printf("Size of Animal struct: %lu bytes\n", sizeof(dog));

    return 0;
}

/*
Expected size:
- type: 20 bytes
- name: 50 bytes
- age: 4 bytes
- kind: 60 bytes
Total = 134 bytes

But the actual printed size will likely be 136 or 140,because of memory padding.

Memory Padding:
The compiler adds padding to align data properly (e.g., aligning `int` to 4-byte boundary).
This makes memory access faster on most hardware, but causes the struct size to increase slightly.
*/
