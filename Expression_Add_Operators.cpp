#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void backtrack(string &num, int target , string curr_path , vector<string> &ans , long long prev_operand , long long curr_sum , int index) {

        if(index == num.length()) {
            if(curr_sum == target) {
                ans.push_back(curr_path);
            }
            return;
        }


        for(int i = index ; i<num.length() ; i++) {

            if(i>index && num[index] == '0') break;
            string curr_str = num.substr(index , i - index + 1);
            long long curr_num = stol(curr_str);

            if(index == 0) {
                backtrack(num , target , curr_str , ans , curr_num , curr_num , i + 1);
            }
            else {
                backtrack(num , target , curr_path + '+' + curr_str , ans , curr_num , curr_sum + curr_num  , i + 1);
                backtrack(num , target , curr_path + '-' + curr_str , ans , -curr_num , curr_sum - curr_num  , i + 1);
                backtrack(num , target , curr_path + '*' + curr_str , ans , prev_operand*curr_num , (curr_sum - prev_operand) + (prev_operand*curr_num)  , i + 1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        string curr_path = "";
        vector<string> ans;

        int index = 0;
        long long curr_sum = 0;
        long long prev_operand = 0;


        backtrack(num , target , curr_path , ans , prev_operand , curr_sum , index);

        return ans;
    }
};