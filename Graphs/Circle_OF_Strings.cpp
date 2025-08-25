#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isCircle(vector<string> &arr) {
        vector<int> in(26, 0), out(26, 0);
        vector<vector<int>> adj(26);

        // Step 1: Build graph
        for (auto &s : arr) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';
            out[u]++, in[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u); // for undirected connectivity check
        }

        // Step 2: Check in-degree == out-degree
        for (int i = 0; i < 26; i++) {
            if (in[i] != out[i]) return 0;
        }

        // Step 3: Check connectivity (ignore zero-degree vertices)
        int start = -1;
        for (int i = 0; i < 26; i++) {
            if (out[i] > 0) { start = i; break; }
        }
        if (start == -1) return 0; // no strings at all

        vector<int> visited(26, 0);
        dfs(start, adj, visited);

        for (int i = 0; i < 26; i++) {
            if ((in[i] > 0 || out[i] > 0) && !visited[i]) return 0;
        }

        return 1;
    }

    void dfs(int u, vector<vector<int>> &adj, vector<int> &visited) {
        visited[u] = 1;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v, adj, visited);
        }
    }
};