#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int i = 0;

        int count = 0;

        for(int j = 0 ; j<s.size() ; j++) {
            if(i == g.size()) return count;
            if(g[i] <= s[j]) {
                i++;
                count++;
            }
        }

        return count;
    }
};