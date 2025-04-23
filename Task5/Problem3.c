#include <stdio.h>

// ascending
void sortAscending(int *arr, int n) {
    int *i, *j, temp;
    for (i = arr; i < arr + n - 1; i++) {
        for (j = i + 1; j < arr + n; j++) {
            if (*i > *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

// descending
void sortDescending(int *arr, int n) {
    int *i, *j, temp;
    for (i = arr; i < arr + n - 1; i++) {
        for (j = i + 1; j < arr + n; j++) {
            if (*i < *j) {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int *arr, int n) {
    int *p;
    for (p = arr; p < arr + n; p++) {
        printf("%d", *p);
        if (p < arr + n - 1) printf(", ");
    }
    printf(",\n");
}

int main() {
    int arr[10];
    int i;

    // Input
    printf("Enter 10 array elements: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort ascending
    sortAscending(arr, 10);
    printf("Array in ascending order: ");
    printArray(arr, 10);

    // Sort descending
    sortDescending(arr, 10);
    printf("Array in descending order: ");
    printArray(arr, 10);

    return 0;
}
