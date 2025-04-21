#include <stdio.h>

int main() {
    //Create a pointer
    //we are giving it a specific address: 0x600000
    //(int *) is used to tell the compiler this number is a pointer to an int

    int *ptr = (int *)0x600000;

    //read the value at that memory address
    //*ptr means "get the value stored at the address the pointer is pointing to"

    printf("Value at address 0x600000: %d\n", *ptr);

    //write a new value to that address
    //store 100 at address 0x600000

    *ptr = 100;

    // Print the new value we just stored at that address
    printf("New value at address 0x600000: %d\n", *ptr);

    return 0;
}
