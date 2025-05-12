#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[50];
    struct Node* next;
};

struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end
void append(struct Node** head, const char* data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printListAndLength(struct Node* head) {
    int length = 0;
    printf("Linked List contents:\n");
    while (head != NULL) {
        printf(" %s\n", head->data);
        head = head->next;
        length++;
    }
    printf("Total Length: %d\n", length);
}

// Main function
int main() {
    struct Node* train = NULL;

    append(&train, "Engine");
    append(&train, "Coach1");
    append(&train, "Coach2");
    append(&train, "Coach3");

    printListAndLength(train);

    return 0;
}