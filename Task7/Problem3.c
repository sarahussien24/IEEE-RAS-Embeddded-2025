#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

// Function to add two complex numbers
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void printComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main() {
    Complex num1, num2, sum;

    // Input
    printf("Enter real and imaginary part of first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary part of second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imag);

    sum = addComplex(num1, num2);
    
    printf("\nSum of the complex numbers: ");
    printComplex(sum);

    return 0;
}
