#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V , false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        ans.push_back(0);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int neighbour : adj[node]) {
                if(!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    ans.push_back(neighbour);
                }
                
            }
        }
        
        return ans;
        
    }
};