#include<bits/stdc++.h>
using namespace std;

int xor0ToN(int n) {
    if(n%4 == 0) return n;
    else if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else return 0;
}

int xorLtoR(int l , int r) {
    return xor0ToN(l-1)^xor0ToN(r);
}
