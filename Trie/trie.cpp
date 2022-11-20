#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char ch;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char c)
    {
        ch = c;
        isTerminal = false;
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
            return root->isTerminal;
        
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("abcd"); 
    cout<<"Present or not "<< t->search("abcd"); 
}