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

void buildFwk(vector<long long>& base, int i, int val, int tam){
    i = tam + i; // jogar o valor da posição pra frente
    base[i] = val; //alocar o valor
    for(int j = i; j > 1; j /= 2){ //For para ir preenchendo os nós da árvore
        base[j/2] = base[j] + base[j ^ 1];
    }
}

long long rsq(vector<long long>& base, int a, int b, int qnt){
    int l = a + qnt;
    int r = b + qnt;
    long long resp = 0;
    for(int i = l, j = r; i < j; i/=2, j/=2){
        if(i%2 == 1){
            resp += base[i++];
        }
        if(j%2 == 1){
            resp += base[--j];
        }
    }
    return resp;
}
