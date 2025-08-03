#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector<bool> isPrime(n , true);
        isPrime[0] = false;
        isPrime[1] = false;

        int count = 0;

        for(int i = 0 ; i*i <= n ; i++) {
            if(isPrime[i] == true) {
                for(int j = i*i ; j<n ; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int i = 0 ; i<n ; i++) {
            if(isPrime[i] == true) count++;
        }

        return count;
    }
};