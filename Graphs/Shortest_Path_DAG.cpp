#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> ans(V , INT_MAX);
        ans[src] = 0;
        queue<int> q;
        q.push(src);
        vector<int> visited(V , false);
        visited[src] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neighbour : adj[node]) {
                if(!visited[neighbour]) {
                    ans[neighbour] = min(ans[neighbour] , ans[node] + 1);
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        for(int i = 0 ; i<V ; i++) if(ans[i] == INT_MAX) ans[i] = -1;
        return ans;
    }
};