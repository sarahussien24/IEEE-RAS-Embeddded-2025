#include <stdio.h>
#include <string.h>

struct Animal {
    char name[50];
    int age;
    char kind[50];
    char type[10];
};

struct Animal createAnimalFromUser() {
    struct Animal a;

    printf("Enter animal type (Dog or Cat): ");
    scanf("%s", a.type);
    printf("Enter name: ");
    scanf("%s", a.name);
    printf("Enter age: ");
    scanf("%d", &a.age);
    printf("Enter kind: ");
    scanf("%s", a.kind);

    return a;
}

void printAnimal(struct Animal a) {
    printf("\n Animal Information \n");
    printf("Type: %s\n", a.type);
    printf("Name: %s\n", a.name);
    printf("Age: %d\n", a.age);
    printf("Kind: %s\n", a.kind);
}

int main() {
    struct Animal myAnimal = createAnimalFromUser();

    printAnimal(myAnimal);

    return 0;
}
