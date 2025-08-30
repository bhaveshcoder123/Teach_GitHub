#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void DFS(int node , int parent , vector<vector<int>> &adj , vector<bool> &visited , vector<int> &disc , vector<int> &low , vector<bool> &artPoint , int timer) {
        disc[node] = low[node] = timer;
        visited[node] = true;
        
        int child = 0;
        
        for(auto &neighbour : adj[node]) {
            if(neighbour == parent) continue;
            else if (visited[neighbour]) {
                low[node] = min(low[node] , disc[neighbour]);
            }
            else {
                timer++;
                child++;
                // Only DFS CHildren Matter take a triangle and explain!!
                DFS(neighbour , node , adj , visited , disc , low , artPoint , timer);
                if(disc[node] <= low[neighbour] && parent != -1) artPoint[node] = true;
                low[node] = min(low[node] , low[neighbour]);
            }
        }
        
        if(parent == -1 && child > 1) artPoint[node] = true;
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> artPoint(V , false);
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V , false);
        int timer = 0;
        
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i])
            DFS(i , -1 , adj , visited , disc , low , artPoint , timer);
        }
        
        vector<int> ans;
        for(int i = 0 ; i<V ; i++) {
            if(artPoint[i]) ans.push_back(i);
        }
        
        if(ans.empty()) return {-1};
        return ans;
    }
};