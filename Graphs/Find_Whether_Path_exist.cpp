#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find whether a path exists from the source to destination.
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j] = 4;
                }
            }
        }
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                
                
                if(nx<0 || nx>=n || ny>=n || ny<0 || (grid[nx][ny] != 3 && grid[nx][ny] != 2)){
                    continue;
                }
                
                if(grid[nx][ny] == 2) return 1;
                
                q.push({nx,ny});
                grid[nx][ny] = 4;
            }
        }
        return 0;
        
    }
};