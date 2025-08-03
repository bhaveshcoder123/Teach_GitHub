#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr_path;

        int n = nums.size();
        int goTill = 1<<n;

        for(int i = 0 ; i<goTill ; i++) {
            curr_path.clear();
            for(int j = 0; j<n ; j++) {
                int temp = 1<<j;
                bool isSet = (i&temp) != 0;
                if(isSet) curr_path.push_back(nums[j]);
            }
            ans.push_back(curr_path);
        }

        return ans;
    }
};