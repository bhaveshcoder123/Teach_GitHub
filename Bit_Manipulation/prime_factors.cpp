#include<bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactor(int num) {
    vector<int> ans;
    for(int i = 2 ; i*i<=num ; i++) {
        if(num%i == 0) {
            while(num%i == 0) {
                ans.push_back(i);
                num = num/i;
            }
        }
    }
    if(num>1) ans.push_back(num);
    return ans;
}

int main() {
    vector<int> ans = getPrimeFactor(1);
    for(int num : ans) cout<<num<<" ";
    cout<<endl;
}