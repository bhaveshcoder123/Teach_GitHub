#include<bits/stdc++.h>
using namespace std;

vector<int> getAllDivisor(int num) {

    vector<int> small;
    vector<int> large; 

    for(int i = 1; i*i <= num ; i++) {
        if(num%i == 0) {
            small.push_back(i);
            int other = num/i;
            if(other != i) {
                large.push_back(other);
            }
        }
    }

    reverse(large.begin() , large.end());

    for(int num : large) small.push_back(num);
    return small;
}

int main() {
    vector<int> ans = getAllDivisor(36);
    for(int num : ans) cout<<num<<" ";
    cout<<endl;
}