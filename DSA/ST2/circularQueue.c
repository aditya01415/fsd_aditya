//wap to implement circular queue using a linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // Point to itself to make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
}
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear) { // Only one element
        free(front);
        front = rear = NULL;
    } else {
        struct Node* temp = front;
        front = front->next;
        rear->next = front; // Maintain circular link
        free(temp);
    }
}
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
        while (temp != front); {
        printf("%d ", temp->data);
        temp = temp->next;
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