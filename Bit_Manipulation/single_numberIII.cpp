#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_sum = 0;
        for(int i = 0 ; i<nums.size() ; i++) {
            xor_sum = xor_sum ^ nums[i];
        }

        int result1 = 0;
        int result2 = 0;

        long long diff_bit = xor_sum & -xor_sum;
        for(int num : nums) {
            if (num & diff_bit) {
                result2 ^= num;
            }
            else result1 ^= num;
        }

        if(result1 > result2) swap(result1 , result2);
        return {result1 , result2};
    }
};