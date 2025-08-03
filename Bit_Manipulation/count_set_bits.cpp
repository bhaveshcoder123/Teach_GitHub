#include<bits/stdc++.h>
using namespace std;

int count_set_bits(int n) {
    int count = 0;
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main() {
    int num;
    cin>>num;
    cout<<count_set_bits(num)<<endl;
}