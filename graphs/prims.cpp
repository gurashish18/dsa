#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,e;
	cin >> n >> e;


	vector<pair<int,int> > adj[n]; 

	for(int i = 0; i<e ; i++){
        int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}	
	
	vector<int> parent(n, -1); 
      
    vector<int> key(n, INT_MAX); 
      
    vector<bool> mst(n, false); 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; // key, index

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    
    while(!pq.empty())
    { 
        int node = pq.top().second; 
        pq.pop(); 
        
        mst[node] = true; 
        
        for (auto nbr : adj[node]) 
        {
            int nbrnode = nbr.first;
            int nbrweight = nbr.second;
            if (mst[nbrnode] == false && nbrweight < key[nbrnode]) 
            {
                parent[nbrnode] = node;
		        key[nbrnode] = nbrweight; 
                pq.push({key[nbrnode], nbrnode});    
            }
        }
            
    } 
    
    for (int i = 1; i < n; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}