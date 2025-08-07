#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        vector<vector<int>> timeline;
        for(int i = 0 ; i<arr.size() ; i++) {
            timeline.push_back({arr[i] , 0});
        }
        for(int i = 0 ; i<dep.size() ; i++) {
            timeline.push_back({dep[i] , 1});
        }
        int maxCount = 0;
        sort(timeline.begin() , timeline.end());
        
        int count = 0;
        
        for(auto &pair : timeline) {
            int timer = pair[0];
            int isEnd = pair[1];
            if(isEnd == 0) count++;
            else count--;
            
            maxCount = max(maxCount , count);
        }
        
        return maxCount;
    }
};