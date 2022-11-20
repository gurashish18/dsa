#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> adj[n+1];
    vector<int> dist(n, INT_MAX);

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    dist[src]=0;

    while(!pq.empty())
    {
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        for(auto nbr:adj[node])
        {
            int nbrnode=nbr.first;
            int nbrweight=nbr.second;

            if(dist[nbrnode]>dist[node]+nbrweight)
            {
                dist[nbrnode]=dist[node]+nbrweight;
                pq.push({dist[nbrnode], nbrnode});
            }
        }
    }

    for(int i:dist)
    {
        cout<<i<<" ";
    }

}