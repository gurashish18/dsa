#include<bits/stdc++.h>
using namespace std;

class StackNode{
    public:
        int data;
        StackNode *next;
};

StackNode* newnode(int x)
{
    StackNode *newNode = new StackNode();
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

int push(int x, StackNode** root)
{
    StackNode *newNode = newnode(x);
    newNode->next=(*root);
    (*root)=newNode;
    return newNode->data;
}

int pop(StackNode **root)
{
    if((*root)==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return INT_MAX;
    }   
    StackNode* temp = (*root);
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
  
    return popped;
}
int peek(StackNode** root)
{
    if((*root)==NULL)
    {
        cout<<"Stack empty"<<endl;
        return INT_MAX;
    }
    return (*root)->data;
}

bool isEmpty(StackNode** root)
{
    return (*root==NULL);
}

int main()
{
    StackNode *root=NULL;
    
    push(1, &root);
    push(2, &root);
    push(3, &root);

    cout<<"Top element "<<peek(&root)<<endl;

    pop(&root);

    push(4, &root);
    push(5, &root);

    while(!isEmpty(&root))
    {
        cout<<peek(&root)<<" ";
        pop(&root);
    }
}