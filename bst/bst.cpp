#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

// TC=O(logN)
Node* insertBST(Node* root, int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }

    if(val>root->data)
        root->right=insertBST(root->right, val);
    else
        root->left=insertBST(root->left, val);
    return root;
}
Node* findinordersucc(Node* root)
{
    if(root==NULL)
        return root;
    while(root->left)
        root=root->left;
    return root;
}
Node* deleteBST(Node* root, int val)
{
    if(root==NULL)
        return NULL;
    
    if(val>root->data)
        return deleteBST(root->right, val);
    else if(val<root->data)
        return deleteBST(root->left, val);
    else
    {
        //0 child
        if(!root->left and !root->right)
        {
            delete(root);
            return NULL;
        }

        // 1child
        if(!root->left and root->right)
        {
            Node* rightsubtree=root->right;
            delete(root);
            return rightsubtree;
        }
        if(!root->right and root->left)
        {
            Node* leftsubtree=root->left;
            delete(root);
            return leftsubtree;
        }
        //2child
        if(root->left and root->right)
        {
            Node* inordersucc=findinordersucc(root->right);
            root->data=inordersucc->data;
            root->right=deleteBST(root->right, inordersucc->data);
            return root;
        }
    }
}

void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node* root=NULL;
    vector<int> bstTree = {5,1,3,4,2,7};
    for(int i:bstTree)
    {
        root = insertBST(root, i);
    }

    cout<<endl<<"Inorder of BST"<<endl;
    inorder(root);
}