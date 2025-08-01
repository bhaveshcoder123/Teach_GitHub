#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool backtrack(int x , int y , string &word , vector<vector<char>>& board , int m , int n , int index , vector<vector<bool>> &visited) {
        
        if(visited[x][y]) return false;


        if(board[x][y] != word[index]) return false;
        if(index == word.length() - 1) return true;
        visited[x][y] = true;

        for(int i = 0 ; i<4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && backtrack(nx , ny , word , board , m , n , index + 1 , visited)) return true;
        }

        visited[x][y] = false;

        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();


        vector<vector<bool>> visited(m , vector<bool>(n , false));

        int index = 0;

        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(board[i][j] == word[index] && backtrack(i , j , word , board , m , n , index , visited)) {
                    return true;
                }
            }
        }

        return false;

    }
};


int main() {
    Solution obj;
    vector<vector<char>> board = {{'A','B'},{'C','D'}};
    string word = "CDBA";
    cout<<obj.exist(board , word)<<endl;
}