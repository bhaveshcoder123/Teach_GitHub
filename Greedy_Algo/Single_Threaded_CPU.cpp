#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        for(int i = 0 ; i<tasks.size() ; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin() , tasks.end());

        long long timer = 0;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        int index = 0;

        while(index < tasks.size() || !pq.empty()) {
            int &i = index;
            if(pq.empty()) timer = max(timer , 1LL*tasks[i][0]);
            
            while(index < tasks.size() && tasks[index][0] <= timer) {
                pq.push({tasks[i][1] , tasks[i][2]});
                index++;
            }

            auto task = pq.top();
            pq.pop();

            timer += task.first;
            ans.push_back(task.second);
        }

        return ans;
    }
};