//wap to implement linear queue using a array
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;  
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    front++;
    if (front > rear) {
        front = rear = -1; // Reset queue when empty
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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