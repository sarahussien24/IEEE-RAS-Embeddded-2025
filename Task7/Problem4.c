#include <stdio.h>

// Enum to represent the days of the week
enum DayOfWeek {
    SATURDAY, SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY
};

const char* checkDayType(enum DayOfWeek day) {
    if (day == FRIDAY || day == SATURDAY) {
        return "Weekend";
    } else {
        return "Weekday";
    }
}

int main() {
    int userInput;
    
    printf("Enter the day number (from 0 to 6):\n");
    scanf("%d", &userInput);

    if (userInput < 0 || userInput > 6) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert the input to enum type
    enum DayOfWeek today = (enum DayOfWeek)userInput;

    printf("Today is a %s.\n", checkDayType(today));
    return 0;
}