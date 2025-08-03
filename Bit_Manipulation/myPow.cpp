#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int N) {
        long long n = N;
        double result = 1;
        if(n<0) {
            n = -n;
            x = 1/x;
        }
        while(n) {
            if(n%2 == 0) {
                x = x*x;
                n = n/2;
            }
            else {
                result *= x;
                n--;
            }
        }
        return result;
    }
};