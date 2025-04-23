#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

void findOddNumbers(int *arr, int size, int *odds, int *count) {
    *count = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 != 0) {
            odds[(*count)++] = arr[i];
        }
    }
}

int main() {
    int arr[MAX_SIZE], odds[MAX_SIZE];
    int size = 0;
    char input[500];
    char *ptr = input;
    int num;
    
    printf("Enter array elements : ");
    fgets(input, sizeof(input), stdin);
    
    while(*ptr != '\0' && size < MAX_SIZE) {
        if(sscanf(ptr, "%d", &num) == 1) {
            arr[size++] = num;
            while(*ptr && !isspace(*ptr)) ptr++;
            while(*ptr && isspace(*ptr)) ptr++;
        } else {
            ptr++;
        }
    }
    
    if(size == 0) {
        printf("No elements entered!\n");
        return 1;
    }
    
    int count;
    findOddNumbers(arr, size, odds, &count);
    
    if(count > 0) {
        printf("Odd numbers are: ");
        for(int i = 0; i < count; i++) {
            printf("%d ", odds[i]);
        }
        printf("\nTotal odd numbers: %d\n", count);
    } else {
        printf("No odd numbers found\n");
    }
    
    return 0;
}