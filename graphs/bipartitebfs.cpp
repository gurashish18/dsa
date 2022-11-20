#include<bits/stdc++.h>
using namespace std;

bool bipartitebfs(int node, vector<int> &color, vector<int> adj[])
{
    queue<int> q;
    color[node]=1;
    q.push(node);

    while(!q.empty())
    {
        int currnode=q.front();
        q.pop();

        for(auto nbr:adj[currnode])
        {
            if(color[nbr]==-1)
            {
                color[nbr]=1-color[currnode];
                q.push(nbr);
            }
            else if(color[nbr]==color[currnode])
                return false;
        }
    }
    return true;
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n+1];
    vector<int> color(n, -1);

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(bipartitebfs(i, color, adj)==false)
                return false;
        }
    }
    return true;
}