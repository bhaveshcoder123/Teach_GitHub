#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        
        for(auto & edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i<V ; i++) {
            if(!indegree[i]) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                if(!indegree[neighbour]) q.push(neighbour);
            }
        }
        
        return ans;
    }
};