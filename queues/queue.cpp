#include<bits/stdc++.h>
using namespace std;

class queueds{
    int front, rear, size, capa;
    int* arr;
    public:
        queueds(int capacity)
        {
            front=0;
            rear=capacity-1;
            capa=capacity;
            size=0;
            arr = new int[capacity];
        }
        bool isEmpty()
        {
            if(size==0)
                return true;
            else
                return false;
        }
        bool isFull()
        {
            if(size==capa)
                return true;
            else
                return false;
        }
        int enqueue(int val)
        {
            if(isFull())
                return INT_MAX;
            
            rear = (rear+1)%capa;
            arr[rear] = val;
            size++;
            return val;
        }
        int dequeue()
        {
            if(isEmpty())
                return INT_MAX;
            
            int val=arr[front];
            front=(front+1)%capa;
            size--;
            return val;
        }
        int frontele()
        {
            if(isEmpty())
                return INT_MAX;
            return arr[front];
        }
        int rearele()
        {
            if(isFull())
                return INT_MAX;
            return arr[rear];
        }
};
int main()
{
    queueds q(5);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue()
         << " dequeued from queue\n";

    cout << "Front item is "
         << q.frontele() << endl;
    cout << "Rear item is "
         << q.rearele() << endl;
}