#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int five = 0;
       int ten = 0;
       int twenty = 0;

       for(int bill : bills) {
        if(bill == 5) {
            five++;
        }
        else if (bill == 10) {
            ten++;
            if(five>0) five--;
            else return false;
        }
        else {
            twenty++;
            if(ten >= 1 && five >= 1) {
                ten--;
                five--;
            }
            else if (five >= 3) {
                five -= 3;
            } 
            else return false;
        } 
       }

       return true; 
    }
};