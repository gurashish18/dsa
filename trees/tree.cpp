#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preorderRec(node* root)
    {
        if(!root)
            return ;

        cout<<root->data<<" ";
        preorderRec(root->left);
        preorderRec(root->right);
    }
void preorderIt(node* root)
{
    stack<node*> st;
    st.push(root);

    while(!st.empty())
    {
        node* curr=st.top();
        st.pop();

        cout<<curr->data<<" ";
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
    }
}
void inorderRec(node* root)
{
    if(!root)
        return ;

    inorderRec(root->left);
    cout<<root->data<<" ";
    inorderRec(root->right);
}
void inorderIt(node* root)
{
    stack<node*> st;
    node* curr=root;

    while(curr!=NULL or !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}
void postorderRec(node* root)
{
    if(!root)
        return;
    
    postorderRec(root->left);
    postorderRec(root->right);
    cout<<root->data<<" ";
}
void postorderIt(node* root)
{
    stack<node*> s1,s2;
    s1.push(root);

    while(!s1.empty())
    {
        node* curr=s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left)
            s1.push(curr->left);
        if(curr->right)
            s1.push(curr->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left=new node(4);
    root->left->right=new node(5);

    // cout<<"Preorder with recursion"<<endl;
    // preorderRec(root);
    // cout<<endl;
    // cout<<"Preorder without recursion"<<endl;
    // preorderIt(root);

    // cout<<"Inorder with recursion"<<endl;
    // inorderRec(root);
    // cout<<endl;
    // cout<<"Inorder without recursion"<<endl;
    // inorderIt(root);

    // cout<<"Postorder traversal using recursion"<<endl;
    // postorderRec(root);
    cout<<"Postorder traversal without recursion"<<endl;
    postorderIt(root);
}