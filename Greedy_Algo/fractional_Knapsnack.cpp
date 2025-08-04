#include<bits/stdc++.h>
using namespace std;

bool comp(vector<double> &a , vector<double> &b) {
    return a[0] > b[0];
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<double>> value_for_each;
        for(int i = 0 ; i<n ; i++) {
            value_for_each.push_back({double(val[i])/wt[i] , double(i)});
        }
        
        double profit = 0;
        
        sort(value_for_each.begin() , value_for_each.end() , comp);
        
        
        for(int i = 0 ; i<n ; i++) {
            if(capacity <= 0) break;
            int index = value_for_each[i][1];
            int capacity_to_take = min(capacity , wt[index]);
            
            capacity -= capacity_to_take;;
            profit += value_for_each[i][0]*capacity_to_take;
        }
        
        return profit;
    }
};