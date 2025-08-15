#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dx[8] = {0 , -1 , -1 , -1 , 0 , 1, 1 , 1};
    int dy[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
    int n,m;
    
    void dfs(int x , int y , vector<vector<char>>& grid , vector<vector<bool>> &visited) {
        visited[x][y] = true;
        for(int i = 0 ; i<8 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || grid[nx][ny] == 'W') continue;
            dfs(nx , ny , grid , visited);
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        int islands = 0;
        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if(grid[i][j] == 'L' && visited[i][j] == false) {
                    islands++;
                    dfs(i , j , grid , visited);
                }
            }
        }
        
        
        return islands;
        
        
    }
};