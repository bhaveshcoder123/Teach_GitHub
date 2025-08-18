#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build adjacency list and indegree array
        for (auto &rel : relations) {
            int u = rel[0] - 1;
            int v = rel[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> course_time(n, 0);

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Topological BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                course_time[neighbour] = max(course_time[neighbour], course_time[node] + time[node]);
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // Add the actual course time
        for (int i = 0; i < n; i++) {
            course_time[i] += time[i];
        }

        return *max_element(course_time.begin(), course_time.end());
    }
};
