#include <bits/stdc++.h>
using namespace std;

vector<int> p, rank;

void dsu_create(vector<int>& p, int n){
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
}

int find(vector<int>& p, int k){
    if(p[k] == k){
        return k;
    }
    else{
        p[k] = find(p, p[k]);
        return p[k];
    }
}

bool igual(vector<int>& p, int k, int l){
    return find(p, k) == find(p, l);
}

void unios_set(vector<int> p, int k, int l){
    int x = find(p, k), y = find(p, l);
    if(rank[x] > rank[y]){
        p[y] = x;
    } 
    else{
        p[x] = y;
        if(rank[x] == rank[y]){
            rank[y]++;
        }
    }
}