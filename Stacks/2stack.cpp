#include<bits/stdc++.h>
#define SIZE 100
using namespace std;

class Stack{
    int top1;
    int top2;
    public:
    int arr[SIZE];
    Stack()
    {
        top1=-1;
        top2=SIZE;
    }
    bool push1(int x);
    bool push2(int x);
    int pop1();
    int pop2();
    int peek1();
    int peek2();
    bool isEmpty1();
    bool isEmpty2();
};

bool Stack::push1(int x)
{
    if(top1+1<top2)
    {
        arr[++top1]=x;
        return true;
    }
    else
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
}
bool Stack::push2(int x)
{
    if(top2-1>top1)
    {
        arr[--top2]=x;
        return true;
    }
    else
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
}

int Stack::pop1()
{
    if(top1<=-1)
    {
        cout<<"Stack underflow"<<endl;
        return INT_MAX;
    }
    int x=arr[top1--];
    return x;
}

int Stack::pop2()
{
    if(top2>=SIZE)
    {
        cout<<"Stack underflow"<<endl;
        return INT_MAX;
    }
    int x=arr[top2++];
    return x;
}

int Stack::peek1()
{
    if(top1>-1)
        return arr[top1];
    else
        return INT_MAX;
}

int Stack::peek2()
{
    if(top2<SIZE)
        return arr[top2];
    else
        return INT_MAX;
}


int main()
{
    Stack s;
    s.push1(1);
    s.push2(2);
    s.push1(3);

    cout<<"Top element "<<s.peek1()<<endl;

    s.pop2();

    s.push2(4);
    s.push1(5);
}