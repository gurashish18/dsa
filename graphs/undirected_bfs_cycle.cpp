#include<bits/stdc++.h>
using namespace std;

bool cyclebfs(int node, int n, vector<int> &visited, vector<int> adj[])
{
    queue<pair<int,int>> q;
    q.push({node,-1});
    visited[node]=1;

    while(!q.empty())
    {
        int currnode=q.front().first;
        int par=q.front().second;
        q.pop();

        for(auto nbr:adj[currnode])
        {
            if(visited[nbr]==0)
            {
                visited[nbr]=1;
                q.push({nbr, currnode});
            }
            else if(nbr != par)
                return true;
        }
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
            if(cyclebfs(i, n, visited, adj))
                return true;
        }
    }
    return false;
}