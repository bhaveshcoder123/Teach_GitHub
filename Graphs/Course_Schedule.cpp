//User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        vector<int> inDegree(n,0);
        for (int i = 0 ; i<m ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 0 ; i<n ; i++) {
            if(!inDegree[i]) q.push(i);
        }
        while(!q.empty()) {
            int index = q.front();
            q.pop();
            ans.push_back(index);
            for (int neighbour : adj[index]) {
                inDegree[neighbour]--;
                if(!inDegree[neighbour]) {
                    q.push(neighbour);
                }
            }
        }
        if (ans.size() != n) ans.clear();
        return ans;
    }
};


