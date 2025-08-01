// Leetcode 131 -> Palindrome Partitioning

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s , int start , int end) {
        while(start<=end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    void backtrack(int index , string &s , vector<string> &curr_path , vector<vector<string>> &ans) {
        if(index >= s.length()) {
            ans.push_back(curr_path);
            return;
        }

        for(int i = index ; i<s.length() ; i++) {
            if(isPalindrome(s , index , i)) {
                string temp = s.substr(index , i - index + 1);
                curr_path.push_back(temp);
                backtrack(i + 1 , s, curr_path , ans);
                curr_path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr_path;
        int index = 0;

        backtrack(index , s , curr_path , ans);
        return ans;

    }
};