#include<bits/stdc++.h>
using namespace std;

bool solve(int node, vector<int> &color, vector<int> adj[])
{
    for(auto nbr:adj[node])
    {
        if(color[nbr]==-1)
        {
            color[nbr]=1-color[node];
            if(solve(nbr, color, adj)==false)
                return false;
        }
        else if(color[nbr]==color[node])
            return false;
    }
    return true;
}

int main()
{
    int n, e;
    cin>>n>>e;

    vector<int> adj[n+1];

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=1;
            if(solve(i, color, adj)==false)
                return false;
        }
    }
    return true;
}