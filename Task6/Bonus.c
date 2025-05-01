#include <stdio.h>
#include <string.h>

struct Animal {
    char name[50];
    int age;
    char kind[50]; 
    char type[10];   
};

void deleteAnimal(struct Animal *a) {
    strcpy(a->name, "");
    a->age = 0;
    strcpy(a->kind, "");
    strcpy(a->type, "");
    printf("Animal data has been cleared.\n");
}
void printAnimal(struct Animal *a) {
    printf("Name: %s\n", a->name);
    printf("Age: %d\n", a->age);
    printf("Kind: %s\n", a->kind);
    printf("Type: %s\n", a->type);
}

int main() {
    struct Animal myAnimal;

    printf("Enter animal type (Dog/Cat): ");
    scanf("%s", myAnimal.type);
    printf("Enter animal name: ");
    scanf("%s", myAnimal.name);
    printf("Enter animal age: ");
    scanf("%d", &myAnimal.age);
    printf("Enter animal kind: ");
    scanf("%s", myAnimal.kind);

    printf("\n Before Deletion \n");
    printAnimal(&myAnimal);
    deleteAnimal(&myAnimal);

    printf("\n After Deletion \n");
    printAnimal(&myAnimal);

    return 0;
}
