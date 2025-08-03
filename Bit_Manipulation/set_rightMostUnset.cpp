#include<bits/stdc++.h>
using namespace std;

int set_rightMostUnset(int n) {
    return n|(n+1);
}

int main() {
    int num;
    cin>>num;
    cout<<set_rightMostUnset(num)<<endl;
}