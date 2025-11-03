//wap to implement queue primitive operator
#include <iostream>
using namespace std;
#define N 5
struct queue {
    int item[N];
    int front, rear;
}q;
 void isempty () 
{
   if( q.rear == -1)
   {
       cout << "Queue is empty" << endl;
   }
   else
   {
       cout << "Queue is not empty" << endl;
   }

}
    void isfull () 
    {
    if(q.rear == N-1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        cout << "Queue is not full" << endl;
    }
    
    }
    void enqueue (int x) 
    {
    if(q.rear == N-1)
    {
        cout << "Queue overflow" << endl;
    }
    else if( q.rear == -1)
    {
        q.front = q.rear = 0;
        q.item[q.rear] = x;
        cout << x << " is inserted" << endl;
    }
    else
    {
        q.rear++;
        q.item[q.rear] = x;
        cout << x << " is inserted" << endl;
    }
    
    }
    void dequeue () 
    {
    if(q.rear == -1)
    {
        cout << "Queue underflow" << endl;
    }
    else if(q.front == q.rear)
    {
        cout << q.item[q.front] << " is deleted" << endl;
        q.front = q.rear = -1;
    }
    else
    {
        cout << q.item[q.front] << " is deleted" << endl;
        q.front++;
    }
    
    }
    int main () 
    {
    q.front = 0;
    q.rear = -1;
    for(int i=1; i<=5; i++)
    {
        enqueue(i);
    }
}
