//wap to implement circular queue using an array
#include <stdio.h>
#include <stdlib.h>
#define MAX 100 
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
}
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear) { // Only one element
        front = rear = -1; // Reset queue when empty
    } else {
        front = (front + 1) % MAX;
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue elements: ");
    display();
    dequeue();
    printf("Queue elements after dequeue: ");
    display();
    return 0;
}