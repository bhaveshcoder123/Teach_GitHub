// User function Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
    vector<int> distance(V, 1e8);
    distance[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            if (distance[u] != 1e8 && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], weight = edge[2];
        if (distance[u] != 1e8 && distance[u] + weight < distance[v]) {
            return {-1};  // Negative weight cycle found
        }
    }

    return distance;
}

};
