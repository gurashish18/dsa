#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<int> adj[], vector<int> &visited, stack<int> &order)
{
    visited[node]=1;

    for(auto nbr:adj[node])
    {
        if(visited[nbr]==0)
            toposort(nbr, adj, visited, order);
    }
    order.push(node);
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n+1];
    vector<int> visited(n, 0);

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> order;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            toposort(i, adj, visited, order);
        }
    }
}