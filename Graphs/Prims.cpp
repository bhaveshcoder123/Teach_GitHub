#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge : edges) {
            adj[edge[0]].push_back({edge[1] , edge[2]});
            adj[edge[1]].push_back({edge[0] , edge[2]});
        }
        
        int cost = 0;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0 , {0,-1}});
        vector<bool> isMST(V , false);
        
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(isMST[node]) continue;
            
            isMST[node] = true;
            cost += dist;
            
            for(auto &neighbour : adj[node]) {
                if(!isMST[neighbour.first]) {
                    pq.push({neighbour.second , {neighbour.first , node}});
                }
            }
        }
        
        return cost;
        
    }
};