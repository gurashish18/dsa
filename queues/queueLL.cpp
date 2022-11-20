#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Queue{
    public:
    Node* front;
    Node* rear;
    Queue()
    {
        front=NULL;
        rear=NULL;        
    }

    int enqueue(int val)
    {
        Node* temp = new Node(val);

        if(rear=NULL)
        {
            rear = front = temp;
            return val;
        }

        rear->next=temp;
        rear=temp;
        return val;
    }
    int dequeue()
    {
        if(front=NULL)
            return INT_MAX;
        
        Node* temp = front;
        int val=temp->data;
        front=front->next;

        if(front=NULL)
            rear=NULL;
        delete(temp);

        return val;
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();

    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}