#include<bits/stdc++.h>
#define SIZE 1000
using namespace std;

class Stack{
    int top;
    public:
    int arr[SIZE];
    Stack()
    {
        top=-1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(top>=(SIZE-1))
    {
        cout<<"Stack overflow"<<endl;
        return false;
    }
    arr[++top]=x;
    return true;
}

int Stack::pop()
{
    if(top<=-1)
    {
        cout<<"Stack underflow"<<endl;
        return INT_MAX;
    }
    int x=arr[top--];
    return x;
}

int Stack::peek()
{
    if(top<=-1 || top>=(SIZE-1))
    {
        cout<<"Stack out of bounds"<<endl;
        return INT_MAX;
    }
    return arr[top];
}

bool Stack::isEmpty()
{
    if(top<=-1)
        return true;
    else
        return false;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout<<"Top element "<<s.peek()<<endl;

    s.pop();

    s.push(4);
    s.push(5);

    while(!s.isEmpty())
    {
        cout<<s.peek()<<" ";
        s.pop();
    }
}