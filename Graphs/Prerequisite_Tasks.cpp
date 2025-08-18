#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[N];
        vector<int> inDegree(N,0);
        for (int i = 0 ; i<P ; i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            inDegree[prerequisites[i].first]++;
        }
        queue<int> q;
        int count = 0;
        for (int i = 0 ; i<N ; i++) {
            if(!inDegree[i]) q.push(i);
        }
        while(!q.empty()) {
            int index = q.front();
            q.pop();
            count++;
            for (int neighbour : adj[index]) {
                inDegree[neighbour]--;
                if(!inDegree[neighbour]) {
                    q.push(neighbour);
                }
            }
        }
        return count == N;
    }
};
