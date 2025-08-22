#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    int sx = KnightPos[0];
    int sy = KnightPos[1];
    int X  = TargetPos[0];
    int Y  = TargetPos[1];
    
    if(sx == X && sy == Y) return 0;  // already there
    
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(N+1, vector<bool>(N+1,false));
    
    q.push({sx, sy});
    visited[sx][sy] = true;
    
    int steps = 0;
    
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [x, y] = q.front();
            q.pop();
            
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx <= 0 || nx > N || ny <= 0 || ny > N || visited[nx][ny]) continue;
                
                if(nx == X && ny == Y) return steps + 1;
                
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        steps++;
    }
    
    return -1; // theoretically shouldn't happen for a knight
}
