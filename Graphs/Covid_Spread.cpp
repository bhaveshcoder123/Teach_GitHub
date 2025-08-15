// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    int helpaterp(vector<vector<int>> hospital) {
        int m = hospital.size();
        int n = hospital[0].size();
        
        int timer = 0;
        queue<pair<int,int>> q;
        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(hospital[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()) {
            int size = q.size();
            bool doneWork = false;
            while(size--) {
                pair<int,int> node = q.front();
                q.pop();
                
                int x = node.first;
                int y = node.second;
                
                for(int i = 0 ; i<4 ; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || hospital[nx][ny] != 1) continue;
                    hospital[nx][ny] = 2;
                    doneWork = true;
                    q.push({nx,ny});
                }
            }
            if(doneWork) timer++;
        }
        
        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(hospital[i][j] == 1) return -1;
            }
        }
        
        return timer;
    }
};