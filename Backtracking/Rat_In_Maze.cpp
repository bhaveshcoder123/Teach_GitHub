// Link -> https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n;
    void backtrack(int x , int y , string &temp , vector<string> &ans , vector<vector<bool>> &visited , vector<vector<int>>& maze) {
        
        if(x == n-1 && y == n-1) {
            ans.push_back(temp);
            return;
        }
        
        visited[x][y] = true;
        
        // down
        
        if(x+1 >= 0 && x+1 < n && maze[x+1][y] == 1 && visited[x+1][y] == 0) {
            temp.push_back('D');
            backtrack(x + 1, y , temp , ans , visited , maze);
            temp.pop_back();
        }
        
        
        // up
        
        if(x-1 >= 0 && x-1 < n && maze[x-1][y] == 1 && visited[x-1][y] == 0) {
            temp.push_back('U');
            backtrack(x - 1, y , temp , ans , visited , maze);
            temp.pop_back();
        }
        
        //left 
        if(y-1 >= 0 && y-1 < n && maze[x][y-1] == 1 && visited[x][y-1] == 0) {
            temp.push_back('L');
            backtrack(x, y-1 , temp , ans , visited , maze);
            temp.pop_back();
        }
        
        //right
        
        if(y+1 >= 0 && y+1 < n && maze[x][y+1] == 1 && visited[x][y+1] == 0) {
            temp.push_back('R');
            backtrack(x, y+1 , temp , ans , visited , maze);
            temp.pop_back();
        }
        
        visited[x][y] = false;
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
       vector<string> ans;
       string temp = "";
       int x = 0;
       int y = 0;
       n = maze.size();
       vector<vector<bool>> visited(n , vector<bool>(n , false));
       if(maze[0][0] == 0) return ans;
       if(maze[n-1][n-1] == 0) return ans;
       
       backtrack(x , y , temp , ans , visited , maze);
       sort(ans.begin() , ans.end());
       return ans;
    }
};