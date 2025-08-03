#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(int row , int col , int number , vector<vector<char>>& board) {
        for(int i = 0 ; i<9; i++) {
            if(board[row][i] == (number + '0')) return false;
            if(board[i][col] == (number + '0')) return false;
            int bRow = (row/3)*3;
            int bCol = (col/3)*3;

            for(int i = bRow ; i<bRow + 3 ; i++) {
                for(int j = bCol ; j<bCol + 3 ; j++) {
                    if(board[i][j] == (number + '0')) return false;
                }
            }
        }

        return true;
    }

    bool backtrack(int row , int col , vector<vector<char>>& board) {
        if(row == 9) return true;
        if(col == 9) {
            return backtrack(row + 1 , 0 , board);
        }

        if(board[row][col] != '.') {
            return backtrack(row , col + 1 , board);
        }

        for(int i = 1 ; i<=9 ; i++) {
            if(check(row , col , i , board)) {
                board[row][col] = i + '0';
                if(backtrack(row , col + 1 , board)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;

        backtrack(row , col , board);
    }
};