#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(int node , int parent , vector<vector<int>> &adj , vector<bool> &visited , vector<int> &disc , vector<int> &low , int timer , vector<vector<int>> &Bridges) {
        disc[node] = low[node] = timer;
        visited[node] = true;

        for(auto &neighbour : adj[node]) {
            if(neighbour == parent) continue;
            else if (visited[neighbour]) {
                low[node] = min(low[node] , low[neighbour]);
            }
            else {
                timer++;
                DFS(neighbour , node , adj , visited , disc , low , timer , Bridges);
                if(disc[node] < low[neighbour]) {
                    Bridges.push_back({node , neighbour});
                }
                low[node] = min(low[node] , low[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int V = n;
        vector<vector<int>> adj(V);

        for(auto &connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V , false);
        vector<int> disc(V);
        vector<int> low(V);

        vector<vector<int>> Bridges;
        int timer = 0;

        DFS(0 , -1 , adj , visited , disc , low , timer , Bridges);

        return Bridges;
    }
};