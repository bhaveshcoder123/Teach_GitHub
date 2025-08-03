#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n) {
    return (n&1);
}

int main() {
    int num;
    cin>>num;
    cout<<isOdd(num)<<endl;
}