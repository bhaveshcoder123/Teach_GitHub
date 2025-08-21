// User Function Template
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
       vector<int> distance(V , INT_MAX);
       vector<vector<pair<int,int>>> adj(V);
       
       for(auto &edge : edges) {
           adj[edge[0]].push_back({edge[1] , edge[2]});
       }
       priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
       distance[src] = 0;
       pq.push({0 , src});
       
       while(!pq.empty()) {
           int node = pq.top().second;
           int dist = pq.top().first;
           pq.pop();
           
          for(auto &neighbour : adj[node]) {
              if(distance[neighbour.first] > dist + neighbour.second) {
                  distance[neighbour.first] = dist + neighbour.second;
                  pq.push({ distance[neighbour.first], neighbour.first});
              }
          }
       }
       
       return distance;
        
    }
};