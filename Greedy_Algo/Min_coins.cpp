#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        int required = N;
        int denominations[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        for(int i = 9 ; i>=0 ; i--) {
                if (denominations[i] <= required && required>0) {
                    int num = required/denominations[i];
                    while(num--) ans.push_back(denominations[i]);
                    required %= denominations[i];
                }
        }
        return ans;
    }
};