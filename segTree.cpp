#include <bits/stdc++.h>
using namespace std;

void sgtCreate(vector<int>& p, vector<int>& ref, int l, int r, int i){
    if(l == r){
        p[i] = l;
    }
    else{
        sgtCreate(p, ref, l, (l + r)/2, i + 2);//nó a esquerda
        sgtCreate(p, ref, (l + r)/2 + 1, r, i + 3);//nó a direita
        int p1 = p[i + 2], p2 = p[i + 3];
        if(ref[p1] <= ref[p2]){//onde ocorre a comparação para poder saber qual o menor número do array buscado
            p[i] = p1;
        } 
        else{
            p[i] = p2;
        }
    }
}

int sgtSol(vector<int> sgt, vector<int> val, int l, int r, int x, int y, int i){
    if(x > r || y < l){
        return -1;
    }
    if(l >= x && r <= y){
        return sgt[i];
    }

    int p1 = sgtSol(sgt, val, l, (l + r)/2, x, y, i + 2);
    int p2 = sgtSol(sgt, val, (l + r)/2 + 1, r, x, y, i + 3);

    if(p1 == -1){
        return p2;
    }
    if(p2 == -1){
        return p1;
    }
    if(val[p1] <= val[p2]){
        return p1;
    }
    else{
        return p2;
    }
}

int main(){
    int qnt, q, x, y;
    cin >> qnt;
    vector<int> base(qnt);
    for(int i = 0; i < qnt; i++){
        cin >> base[i];
    }
    vector<int> sgt(qnt*4);
    sgtCreate(sgt, base, 0, qnt - 1, 1);
    cin >> q;
    while(q--){
        cin >> x >> y;
        cout << base[sgtSol(sgt, base, 0, qnt - 1, x, y, 1)] << "\n";
    }
}

