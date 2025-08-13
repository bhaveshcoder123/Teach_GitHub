#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(vector<int> &ans , vector<vector<int>>&adj , vector<bool>&visited , int node) {
        visited[node] = true;
        
        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) dfs(ans , adj , visited , neighbour);
        }
        
        ans.push_back(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> adj(V);
        vector<bool>visited(V,false);
        
        for(auto & edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i = 0 ; i<V ; i++) {
            if(!visited[i]) dfs(ans , adj , visited , i);
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};