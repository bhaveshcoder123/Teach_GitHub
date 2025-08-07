#include<bits/stdc++.h>
using namespace std;


bool comp(vector<int> &a , vector<int> &b) {
    return a[0] > b[0];
}

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<vector<int>> jobs;

        int n = deadline.size();

        int maxTime = 0;

        for(int i = 0 ; i<n ; i++) {
            jobs.push_back({profit[i] , deadline[i]});
            maxTime = max(maxTime , deadline[i]);
        }

        vector<int> parent(maxTime + 1);
        for(int i = 0 ; i<=maxTime ; i++) {
            parent[i] = i;
        }

        sort(jobs.begin() , jobs.end() , comp);

        int total_jobs = 0;
        int total_profit = 0;

        for(int i = 0; i<n ; i++) {
            int curr_deadline = jobs[i][1];
            int curr_profit = jobs[i][0];

            int k = curr_deadline;
            while(k>0 && parent[k] != k) {
                parent[k] = parent[parent[k]];
                k = parent[k];
            }

            if(k <= 0 || parent[k] != k) continue;

            total_jobs++;
            total_profit += curr_profit;

            parent[k] = k - 1;
        }

        return {total_jobs , total_profit};
    }
};