#include <stdio.h>
#include <string.h>

#define STUDENT_COUNT 5

typedef struct {
    unsigned int roll : 4;   // 4 bits
    unsigned int age  : 8;   // 8 bits
    unsigned int marks: 3;   // 3 bits
    char name[50];
    char address[100];
} student_info;

void print_students(student_info students[], int count) {
    for(int i = 0; i < count; i++) {
        printf("Student %d:\n", i+1);
        printf("  Roll No : %u\n", students[i].roll);
        printf("  Age     : %u\n", students[i].age);
        printf("  Marks   : %u\n", students[i].marks);
        printf("  Name    : %s\n", students[i].name);
        printf("  Address : %s\n\n", students[i].address);
    }
}

int main() {
    student_info students[STUDENT_COUNT] = {
        {1, 20, 5, "Sara", "Cairo"},
        {2, 21, 6, "Sama", "Alexandria"},
        {3, 19, 7, "Hana", "Giza"},
        {4, 22, 4, "Salma", "Mansoura"},
        {5, 20, 3, "Roaa", "Aswan"}
    };

    print_students(students, STUDENT_COUNT);

    printf("Size of student_info struct: %zu bytes\n", sizeof(student_info));

    return 0;
}
