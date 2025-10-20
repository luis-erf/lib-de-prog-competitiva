//Lógica de DP
//Knapsack => códigos em que pega-se os valores possíveis como linha da matriz e a coluna são os estados que vão de 0 até o estado procurado
vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
for(int i = 1; i < n + 1; i++){
    for(int j = 1; j < m + 1; j++){
        if(item[i - 1].first <= j){
            mat[i][j] = max(mat[i - 1][j], mat[i - 1][j - item[i - 1].first] + item[i - 1].second);
        }
        else{
            mat[i][j] = mat[i - 1][j];
        }
    }
}

//Lógica greedy
//Load balance => questões que tem caixas para colocar itens que podem ser ordenados o que permite colocar eles com two pointers partindo colocando sempre os dois valores dos ponteiros na mesma caixa
int n, d, v;
cin >> n >> d >> v;
while(n != 0 && d != 0 && v != 0){
    vector<int> m(n), e(n), base(n, 0);
    for(int i = 0; i < n; i++){
        cin >> m[i];
    }
    for(int i = 0; i < n; i++){
        cin >> e[i];
    }
    sort(m.begin(), m.end());
    sort(e.begin(), e.end());
    int l = 0, r = n - 1;
    for(l, r; l < n; l++, r--){
        base[l] += m[l] + e[r];
    }
    int resp = 0;
    for(auto x : base){
        if(x - d > 0){
            resp += (x - d)*v;
        }
    }
    cout << resp << "\n";
    cin >> n >> d >> v;

}

//Análise de grid/vetor => sempre buscar o mais a direita ou a esquerda. Não fazer uma análise direta de todas as condições
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int qnt, x, a;
    string base;
    cin >> qnt;
    for(int j = 0; j < qnt; j++){
        a = 0;
        cin >> x >> base;
        vector<bool> comp(x, false);
        for(int i = 0; i < x; i++){
            if(!comp[i]){
                if(base[i] == '.'){
                    comp[i] = true;
                    comp[i + 1] = true;
                    comp[i + 2] = true;
                    a++;
                }
            }
        }
        cout << "Case " << j + 1 << ": " << a << "\n";
    }
    return 0;
}

//Coin change problema => Analisar em um vetor 1d as combinações para atingir o pedido
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> coins = {1, 5, 10, 25, 50};
    vector<long long> dp(7490, 0);
    
    dp[0] = 1;
    
    for (int coin : coins) {
        for (int value = coin; value <= 7489; value++) {
            dp[value] += dp[value - coin];
        }
    }
    
    int n;
    while (cin >> n) {
        cout << dp[n] << "\n";
    }
    
    return 0;
}
//Pseudocódigo do problema do troco
 F[0] ← 0;
 for i ← 1 to n do
 temp, j ← ∞, 1;
 while j ≤ m ∧ i ≥ D[j] do
 temp ← min(F[i − D[j]], temp);
 j ← j + 1;
 F[i] ← temp + 1;
 return F[n];

//Questões de manipulação de strings grande => Fazer a lógica simples mas em python
// x = int(input())

// def solve(n):
//     maior = 0
//     for i in str(n):      
//         digit = int(i)
//         if digit > maior:
//             maior = digit
//     return maior

// resp = 0
// while x != 0:
//     maior_digito = solve(x)
//     x -= maior_digito
//     resp += 1

// print(resp)
