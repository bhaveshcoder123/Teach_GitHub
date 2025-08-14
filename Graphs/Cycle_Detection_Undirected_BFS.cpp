#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        queue<pair<int,int>> q;
        vector<bool> visited(V ,false);
        
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i]) {
                q.push({i,-1});
                visited[i] = true;
                
                while(!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();
                    int node = p.first;
                    int parent = p.second;
                    
                    for(int neighbour : adj[node]) {
                        if(visited[neighbour] && neighbour != parent) return true;
                        else if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push({neighbour , node});
                        }
                    }
                    
                }
            }
        }
        
        return false;
    }
};