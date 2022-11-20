#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int u;
    int v;
    int w;
    node(int f, int s, int t)
    {
        u=f;
        v=s;
        w=t;
    }
};

bool cmp(node a, node b) {
    return a.w < b.w; 
}

int findparent(int node, vector<int> &parent)
{
    if(node==parent[node])
        return node;
    return parent[node] = findparent(parent[node], parent);
}

void unionop(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findparent(u, parent);
    v = findparent(v, parent);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, e, cost=0;
    cin>>n>>e;

    vector<node> edges;
    vector<int> rank(n, 0);
    vector<int> parent(n);
    for(int i=0;i<n;i++)
        parent[i]=i;

    for(int i=0;i<e;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back(node(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp); 

    for(auto i:edges)
    {
        if(findparent(i.u, parent) != findparent(i.v, parent))
        {
            cost+=i.w;
            unionop(i.u, i.v, rank, parent);
        }
    }

    cout<<"MINIMUM COST="<<cost;
}