#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(0);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                visited[node] = true;
                ans.push_back(node);

                // Reverse iterate so that smaller neighbours get visited first
                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    int neighbour = adj[node][i];
                    if (!visited[neighbour]) {
                        st.push(neighbour);
                    }
                }
            }
        }

        return ans;
    }
};