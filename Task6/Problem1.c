#include <stdio.h>
#include <string.h>

struct Dog {
    char name[50];
    int age;
    char kind[50];
    char food[50];
    char ownerName[50];
};

int main() {
    struct Dog myDog;

    printf("Enter dog's name: ");
    fgets(myDog.name, sizeof(myDog.name), stdin);
    myDog.name[strcspn(myDog.name, "\n")] = '\0';

    printf("Enter dog's age: ");
    scanf("%d", &myDog.age);
    getchar(); 

    printf("Enter dog's kind: ");
    fgets(myDog.kind, sizeof(myDog.kind), stdin);
    myDog.kind[strcspn(myDog.kind, "\n")] = '\0';

    printf("Enter dog's favorite food: ");
    fgets(myDog.food, sizeof(myDog.food), stdin);
    myDog.food[strcspn(myDog.food, "\n")] = '\0';

    printf("Enter owner's name: ");
    fgets(myDog.ownerName, sizeof(myDog.ownerName), stdin);
    myDog.ownerName[strcspn(myDog.ownerName, "\n")] = '\0';

    printf("\n Dog Information \n");
    printf("Name       : %s\n", myDog.name);
    printf("Age        : %d years\n", myDog.age);
    printf("Kind : %s\n", myDog.kind);
    printf("Food       : %s\n", myDog.food);
    printf("Owner      : %s\n", myDog.ownerName);

    return 0;
}