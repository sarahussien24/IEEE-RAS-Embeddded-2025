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

void enqueue(struct Queue* q, char value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) { 
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = value;
    }
}

char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return '\0';
    } else {
        char value = q->arr[q->front];
        q->front++;
        if (q->front > q->rear) { 
            q->front = q->rear = -1;
        }
        return value;
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    char value = dequeue(&q);
    printf("Dequeued value: %c\n", value);

    return 0;
}