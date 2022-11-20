#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited)
{
    visited[node]=1;

    for(auto nbr:adj[node])
    {
        if(visited[nbr]==0)
            dfs(nbr, adj, visited);
    }
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

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i, adj, visited);
        }
    }

}