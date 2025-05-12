#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    char arr[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->front == -1);
}

int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

char getFront(struct Queue* q) {
    return (isEmpty(q) ? '\0' : q->arr[q->front]);
}

char getRear(struct Queue* q) {
    return (isEmpty(q) ? '\0' : q->arr[q->rear]);
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("Is Empty: %d\n", isEmpty(&q));
    printf("Is Full: %d\n", isFull(&q));
    printf("Front: %c\n", getFront(&q));
    printf("Rear: %c\n", getRear(&q));

    return 0;
}