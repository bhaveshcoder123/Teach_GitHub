#include<bits/stdc++.h>
using namespace std;

bool check_power_of_two(int n) {
    return (n&(n-1)) == 0;
}

int main() {
    int num;
    cin>>num;
    cout<<check_power_of_two(num)<<endl;
}