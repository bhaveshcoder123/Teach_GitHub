#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    bool dfs(int node , vector<bool> &visited , vector<vector<int>> &adj) {
        visited[node] = true;
        
        bool unvisited = false;
        for(int i = 0 ; i<adj.size() ; i++) {
            if(!visited[i]) unvisited = true;
        }
        if(!unvisited) return true;
        
        for(int &neighbour : adj[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour , visited , adj)) return true;
            }
        }
        
        visited[node] = false;
        return false;
    }
    
    bool check(int n, int m, vector<vector<int>> edges) {
        int V = n;
        vector<vector<int>> adj(V);
        
        for(auto &edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        
        vector<bool> visited(V , false); 
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i]) {
                if(dfs(i , visited , adj)) return true;
            }
        }
        
        return false;
    }
};