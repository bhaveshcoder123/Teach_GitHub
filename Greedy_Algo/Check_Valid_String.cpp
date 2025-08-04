#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        int n = s.length();

        for(char ch : s) {
            if(ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }
            if(high < 0) return false;
            if(low < 0) low = 0;
        }
        return low == 0;
    }
};