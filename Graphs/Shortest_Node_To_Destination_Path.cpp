// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> topoSort(vector<vector<pair<int,int>>> &adj) {
        int V = adj.size();
        vector<int> ans;
        vector<int> indegree(V);
        queue<int> q; 
        for(int i = 0; i<V ; i++) {
            for(auto& neighbour : adj[i]) {
                indegree[neighbour.first]++;
            }
        }
        
        for(int i = 0 ; i<V ; i++) {
            if(!indegree[i]) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto &neighbour : adj[node]) {
                indegree[neighbour.first]--;
                if(!indegree[neighbour.first]) q.push(neighbour.first);
            }
        }
        
        return ans;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1] , edge[2]});
        }
        
        vector<int> topoSortArr = topoSort(adj);
        vector<int> distance(V , INT_MAX);
        distance[0] = 0;
        
        for(int i = 0 ; i<V ; i++) {
            if(distance[i] != INT_MAX) {
                for(auto &neighbour : adj[i]) {
                    int node = neighbour.first;
                    int dist = neighbour.second;
                    distance[node] = min(distance[node] , distance[i] + dist);
                }
            }
        }
        for(int i = 0 ; i<V ; i++) if(distance[i] == INT_MAX) distance[i] = -1;
        return distance;
        
    }
};
