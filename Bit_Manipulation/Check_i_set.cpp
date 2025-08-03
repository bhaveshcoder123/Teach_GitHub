#include<bits/stdc++.h>
using namespace std;

bool check_i_set(int n , int i) {
    return (n&(1<<i))!=0;
}

int main() {
    int num,i;
    cin>>num>>i;
    cout<<check_i_set(num,i)<<endl;
}