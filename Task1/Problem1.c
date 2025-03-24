#include <stdio.h>

int main() {
    int num, max, min;
    int first_input = 1; 

    printf("Enter numbers :\n");

    while (1) {
        scanf("%d", &num);

        if (num == -1)
            break;

        if (first_input) {
            max = min = num;
            first_input = 0;
        } else {
            if (num > max)
                max = num;
            if (num < min)
                min = num;
        }
    }

    if (first_input) {
        printf("No valid numbers entered.\n");
    } else {
        printf("Largest: %d\nSmallest: %d\n", max, min);
    }

    return 0;
}
