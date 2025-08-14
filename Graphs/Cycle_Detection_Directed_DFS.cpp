#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node , vector<bool> &visited , vector<bool> &path , vector<vector<int>> &adj) {
        visited[node] = true;
        path[node] = true;
        for (int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                if(dfs(neighbour , visited , path , adj)) return true;
            } 
            else if (path[neighbour]) return true;
        }
        path[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V,false);
        vector<bool> path(V,false);
        
        for (int i = 0 ; i<V ; i++) {
            if(!visited[i]) {
                if(dfs(i,visited,path,adj)) return true;
            }
        }
        return false;
    }
};