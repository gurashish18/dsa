#include<bits/stdc++.h>
using namespace std;

bool cycledfs(int node, vector<int> &visited, vector<int> &dfsvisited, vector<int> adj[])
{
    visited[node]=1;
    dfsvisited[node]=1;

    for(auto nbr:adj[node])
    {
        if(visited[nbr]==0)
        {
            if(cycledfs(nbr, visited, dfsvisited, adj))
                return true;
        }
        else if(dfsvisited[nbr]==true)
            return true;
    }
    dfsvisited[node] =0;
    return false;
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n+1];
    vector<int> visited(n,0);
    vector<int> dfsvisited(n,0);

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
            if(cycledfs(i, visited, dfsvisited, adj))
                return true;
        }
    }
    return false;
}