#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getNodeValue(struct Node* head, int position) {
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    return (temp != NULL) ? temp->data : -1; 
}

void insertNode(struct Node** head, int position, int newData) {
    struct Node* newNode = createNode(newData);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    
    printf("Initial List: ");
    printList(head);
    
    printf("Value at position 1: %d\n", getNodeValue(head, 1));

    insertNode(&head, 1, 15);
    printf("List after insertion: ");
    printList(head);

    return 0;
}