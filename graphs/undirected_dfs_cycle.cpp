#include<bits/stdc++.h>
using namespace std;

bool cycledfs(int node, int parent, vector<int> &visited, vector<int> adj[])
{
    visited[node]=1;

    for(auto nbr:adj[node])
    {
        if(visited[nbr]==0)
        {
            if(cycledfs(nbr, node, visited, adj))
                return true;
        }
        else if(nbr != parent)
            return true;
    }
    return false;
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n+1];
    vector<int> visited(n,0);

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            if(cycledfs(i, -1, visited, adj))
                return true;
        }
    }
    return false;
}