#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbour : graph[node]) {
                        if (color[neighbour] == -1) {
                            q.push(neighbour);
                            color[neighbour] = 1 - color[node];
                        } else if (color[node] == color[neighbour])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};