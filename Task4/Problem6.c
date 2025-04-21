#include <stdio.h>

int main() {
    // Declare a normal integer variable 'a' with value 7
    int a = 7;
    
    // Declare an integer pointer 'aPtr' and make it point to the address of 'a'
    // 'aPtr' now stores the memory address of 'a'
    int *aPtr = &a; // '&a' means "address of a in memory"

    // Print the address of 'a' and the value of pointer 'aPtr' (which is 'a's address)
    // %p is used to print memory addresses (in hexadecimal format)
    printf("Address of a is %p\nValue of aPtr is %p\n\n", &a, aPtr);
    // The output will be identical because 'aPtr' holds 'a's address
    
    // Print the value of 'a' and the value that 'aPtr' points to
    // '*aPtr' means "the value stored at the address contained in 'aPtr'"
    printf("Value of a is %d\nValue of *aPtr is %d\n\n", a, *aPtr);
    // Both will print 7 because '*aPtr' accesses 'a's value

    // Demonstrate that * and & are complementary operators (they undo each other)
    printf("Showing that * and & are complements of each other\n");
    
    // '&*aPtr' means "address of the value pointed to by 'aPtr'" (which is 'a's address)
    // '*&aPtr' means "value at the address of 'aPtr'" (which is 'a's address stored in 'aPtr')
    printf("&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr);
    // Both will print the same address (address of 'a')

    return 0;
}