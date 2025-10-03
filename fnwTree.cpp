#include <bits/stdc++.h>
using namespace std;

//Base para resolver questões que envolvam a frequência de dados valores em um intervalo do array
void build(vector<int>& base, vector<int>& frq){
    for(int i = 0; i < base.size(); i++){
        frq[base[i]]++;
    }
}

void cf(vector<int>& frq, vector<int>& cmf){
    for(int i = 1; i < frq.size(); i++){
        cmf[i] = cmf[i - 1] + frq[i];
    }
}

//Base para resolver a Range sum querry
void build_rsm(vector<int>& base, vector<int>& rsm){
    for(int i = 1; i < base.size() + 1; i++){
        rsm[i] = rsm[i - 1] + base[i - 1];
    }
}

int resp(vector<int>& rsm, int l, int r){
    return rsm[r] - rsm[l];
}
