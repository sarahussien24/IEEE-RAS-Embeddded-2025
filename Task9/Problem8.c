#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void printStack() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void swapTopTwo() {
    if (top < 1) {
        printf("Not enough elements to swap\n");
        return;
    }
    int temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printf("Before swap:\n");
    printStack();
    
    swapTopTwo();
    
    printf("After swap:\n");
    printStack();

    return 0;
}