#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long divide(long long dividend, long long divisor) {
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        divisor = abs(divisor);
        dividend = abs(dividend);
        long long answer = 0;
        while(dividend >= divisor) {
            long long temp = divisor;
            int count = 0;
            while(dividend >= (temp << 1)) {
                temp = temp<<1;
                count++;
            }
            dividend -= temp;
            answer += (1<<count);
        }
        return isNegative ? -answer : answer;
    }
};