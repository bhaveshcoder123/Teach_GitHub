#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char , vector<char>> adj;
        unordered_set<char> st;

        // Step 1: collect all characters
        for (auto &w : words) {
            for (char c : w) st.insert(c);
        }

        int n = words.size();
        for (int k = 1; k < n; k++) {
            string word1 = words[k-1];
            string word2 = words[k];
            
            int i = 0, j = 0;
            while (i < word1.length() && j < word2.length() && word1[i] == word2[j]) {
                i++; j++;
            }
            
            if (j == word2.length() && i < word1.length()) {
                // invalid: prefix case
                return "";
            }
            
            if (i < word1.length() && j < word2.length()) {
                adj[word1[i]].push_back(word2[j]);
                st.insert(word1[i]);
                st.insert(word2[j]);
            }
        }
        
        // Step 2: indegree
        unordered_map<char , int> indegree;
        for (auto c : st) indegree[c] = 0;
        
        for (auto &it : adj) {
            for (char c : it.second) {
                indegree[c]++;
            }
        }
        
        // Step 3: topological sort
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) q.push(p.first);
        }
        
        string ans = "";
        while (!q.empty()) {
            char letter = q.front(); q.pop();
            ans.push_back(letter);
            
            for (char c : adj[letter]) {
                indegree[c]--;
                if (indegree[c] == 0) q.push(c);
            }
        }
        
        // Step 4: check for cycle
        if (ans.size() < st.size()) return "";
        return ans;
    }
};