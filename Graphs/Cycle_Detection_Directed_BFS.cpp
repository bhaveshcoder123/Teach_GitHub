#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        int count = 0;
        vector<int> inDegree(adj.size() , 0);
        for (int i = 0 ; i<V ; i++) {
            for (int neighbour : adj[i]) {
                inDegree[neighbour]++;
            }
        }
        queue<int> q;
        for (int i = 0 ; i<V ; i++) {
            if(!inDegree[i]) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int neighbour : adj[node]) {
                inDegree[neighbour]--;
                if(!inDegree[neighbour]) q.push(neighbour);
            }
        }
        return count != V;
    }
};