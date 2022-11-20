#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int e, vector<int> adj[])
{
    vector<int> visited(n+1, 0);

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            queue<int> q;
            q.push(i);
            visited[i]=1;

            while(!q.empty())
            {
                int curr=q.front();
                q.pop();

                for(auto nbr:adj[curr])
                {
                    if(visited[nbr]==0)
                    {
                        q.push(nbr);
                        visited[nbr]=1;
                    }
                }
            }
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<int> adj[n+1];

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(n,e,adj);
}