#include <stdio.h>

struct Person {
    char name[50];
    int age;
    float height;
};

void printPerson(struct Person p) {
    printf("\n Person Information \n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f cm\n", p.height);
}

int main() {
    struct Person person1;

    printf("Enter name: ");
    scanf("%s", person1.name);

    printf("Enter age: ");
    scanf("%d", &person1.age);

    printf("Enter height : ");
    scanf("%f", &person1.height);
    
    printPerson(person1);

    return 0;
}
