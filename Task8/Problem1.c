#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

//to reverse sort uncomment and comment
#define ASCENDING_SORT
// #define DESCENDING_SORT

void inputArray(int arr[], int size);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    int arr[SIZE];
    
    inputArray(arr, SIZE);

#ifdef ASCENDING_SORT
    sortAscending(arr, SIZE);
#elif defined(DESCENDING_SORT)
    sortDescending(arr, SIZE);
#else
    printf("No sorting macro defined.\n");
    return 1;
#endif
    printArray(arr, SIZE);
    return 0;
}

// take input from user
void inputArray(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// sort array in ascending order
void sortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// sort array in descending order
void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// print the array
void printArray(int arr[], int size) {
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}