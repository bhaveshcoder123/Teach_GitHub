#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void dfs(int node , vector<bool> &visited , vector<int> adj[]) {
        visited[node] = true;
        
        for(int &neighbour : adj[node]) {
            if(!visited[neighbour]) {
                dfs(neighbour , visited , adj);
            }
        }
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
        vector<bool> visited(V , false);
        vector<int> degree(V , 0);
        
        int start = -1;
        int even = 0;
        for(int i = 0 ; i<V ; i++) {
            degree[i] = adj[i].size();
            if(degree[i] % 2 == 0) even++;
            if(degree[i] && start == -1) start = i;
        }
        
        int odd = V - even;
        dfs(start , visited , adj);
        
        if(start == -1) return 2;
        
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i]) {
                if(degree[i]) return 0;
            }
        }
        
        
        if(even == V) return 2;
        if(odd == 2) return 1;
        
        return 0;
    }
};