#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int answer = 0;

        for(int i = 0 ; i<32 ; i++) {
            int count = 0;
            int temp = 1<<i;
            for(int j = 0 ; j<nums.size() ; j++) {
                int num = nums[j];
                bool isSet = (num & temp) != 0;
                if(isSet) count++;
            }
            if(count%3 == 1) answer = answer | temp;
        }

        return answer;
    }
};