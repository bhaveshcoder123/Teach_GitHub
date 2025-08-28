#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a , vector<int> &b) {
    return a[2] < b[2];
}

class DSU {
    public:
    vector<int> parent,rank;
    int n;
    DSU(int size) {
        this->n = size;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0 ; i<n ; i++) parent[i] = i;
        for(int i = 0 ; i<n ; i++) rank[i] = 0;
    }
    
    bool unite(int a , int b) {
        
        int i = a;
        
        while(parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        
        int j = b;
        
        while(parent[j] != j) {
            parent[j] = parent[parent[j]];
            j = parent[j];
        }
        
        if(i == j) return false;
        
        a = i;
        b = j;
        
        if(rank[a] == rank[b]) {
            parent[b] = a;
            rank[a]++;
        }
        
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        
        else parent[a] = b;
        
        return true;
    }
};

class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        
        sort(edges.begin() , edges.end() , comp);
        int cost = 0;
        DSU dsu(V);
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            if(dsu.unite(u,v)) {
                cost += weight;
            }
        }
        
        return cost;   
    }
};