#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void backtrack(int node , vector<vector<int>>& adj , vector<int> &ans , vector<bool> &visited) {
        visited[node] = true;
        ans.push_back(node);
        
        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                backtrack(neighbour , adj , ans , visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V , false);
        backtrack(0 , adj , ans , visited);
        return ans;
    }
};