#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtPosition(int data, int position) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
  
    struct Node* current = head;
    int i;
    for (i = 1; i < position - 1 && current->next != head; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(5, 1);
    insertAtPosition(15, 3); 
    printf("Circular Linked List:\n");
    displayList();

    return 0;
}