#include<iostream>
using namespace std;
#define N 6

struct queue {
    int item[N];
    int front, rear;
} q;

void insert(int x) {
    if ((q.rear + 1) % N == q.front) {
        cout << "Queue is full" << endl;
    } else {
        q.rear = (q.rear + 1) % N;
        q.item[q.rear] = x;
        if (q.front == -1) q.front = 0;
    }
}

void deletee() {
    if (q.front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Deleted: " << q.item[q.front] << endl;
        if (q.front == q.rear) {
            q.front = q.rear = -1;
        } else {
            q.front = (q.front + 1) % N;
        }
    }
}

int main() {
    q.front = q.rear = -1;

    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    insert(30);
    insert(35); 

    cout << "Queue elements: ";
    for (int i = q.front; i != q.rear; i = (i + 1) % N) {
        cout << q.item[i] << " ";
    }
    cout << q.item[q.rear] << endl;

    deletee();
    deletee();

    cout << "After deletion: ";
    for (int i = q.front; i != q.rear; i = (i + 1) % N) {
        cout << q.item[i] << " ";
    }
    cout << q.item[q.rear] << endl;

    insert(35);
    cout << "After inserting 35: ";
    for (int i = q.front; i != q.rear; i = (i + 1) % N) {
        cout << q.item[i] << " ";
    }
    cout << q.item[q.rear] << endl;

    return 0;
} 
   
    
       

