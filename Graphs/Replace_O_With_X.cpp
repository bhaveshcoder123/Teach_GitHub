#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i = 0 ; i<m ; i++) {
            if(mat[i][0] == 'O') {
                q.push({i,0});
                mat[i][0] = '#';
            }
            if(mat[i][n-1] == 'O') {
                q.push({i,n-1});
                mat[i][n-1] = '#';
            }
        }
        
        for(int i = 0 ; i<n ; i++) {
            if(mat[0][i] == 'O') {
                q.push({0,i});
                mat[0][i] = '#';
            }
            if(mat[m-1][i] == 'O') {
                q.push({m-1,i});
                mat[m-1][i] = '#';
            }
        }
        
        while(!q.empty()) {
            pair<int,int> node = q.front();
            q.pop();
            
            int x = node.first;
            int y = node.second;
            mat[x][y] = '#';
            
            for(int i = 0 ; i<4 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || mat[nx][ny] != 'O') continue;
                q.push({nx,ny});
            }
        }
        
        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(mat[i][j] == '#') mat[i][j] = 'O';
                else if(mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};