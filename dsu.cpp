#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& base, int a){
    if(base[a] == a){
        return a;
    }
    else{
        return find(base, base[a]);
    }
}

void dsu(vector<int>& base, vector<int>& tam, int a, int b, int& maior, int&resp){
    int p1 = find(base, a), p2 = find(base, b);
    if(base[p1] == base[p2]){
        return;
    }
    else if(tam[p1] < tam[p2]){
        base[p1] = p2;
        tam[p2] += tam[p1];
        if(tam[p2] > maior){
            maior = tam[p2];
        }
        resp--;
    }
    else{
        base[p2] = p1;
        tam[p1] += tam[p2];
        if(tam[p1] > maior){
            maior = tam[p1];
        }
        resp--;
    }
}
