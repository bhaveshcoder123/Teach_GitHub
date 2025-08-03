#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        vector<bool> visitedCol;
        vector<bool> visitedRightDiag;
        vector<bool> visitedLeftDiag;
    void backtrack(vector<vector<string>> &ans , vector<string> &board , int x , int n) {

        if(x == n) {
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i<n ; i++){
            if(!visitedCol[i] && !visitedRightDiag[x - i + n-1] && !visitedLeftDiag[x + i]) {
                board[x][i] = 'Q';
                visitedCol[i] = true;
                visitedRightDiag[x - i + n-1] = true;
                visitedLeftDiag[x + i] = true;
                backtrack(ans , board , x + 1 , n);
                board[x][i] = '.';
                visitedCol[i] = false;
                visitedRightDiag[x - i + n-1] = false;
                visitedLeftDiag[x + i] = false;
            }
        }
       
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n , string(n , '.'));
        vector<bool> visitedCol1(n , false);
        vector<bool> visitedRightDiag1(2*n - 1 , false);
        vector<bool> visitedLeftDiag1(2*n - 1 , false);

        visitedCol = visitedCol1;
        visitedRightDiag = visitedRightDiag1;
        visitedLeftDiag = visitedLeftDiag1;
        backtrack(ans, board , 0 , n);
        return ans;
    }
};