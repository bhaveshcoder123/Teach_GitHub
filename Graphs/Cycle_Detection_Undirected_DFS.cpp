#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node , int parent , vector<vector<int>>& adj , vector<bool> &visited) {
        visited[node] = true;
        for (int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour,node,adj,visited)) return true;
            }
            else if (neighbour != parent) return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V,false);
        for (int i = 0 ; i<V ; i++) {
            if(!visited[i] && dfs(i,-1,adj,visited)) {
                return true;
            }
        }
        return false;
    }
};