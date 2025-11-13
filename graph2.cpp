//dijkstra
bool dijkstra(vector<vector<pair<int, int>>>& mat, vector<int>& dist, int s, int t, int n) {
    vector<int> mark(n, 0);              
         
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> h;

    dist[s] = 0;
    h.emplace(0, s, s);

    int w, p, v = s;
    while(h.size() > 0) {            
        v = get<1>(h.top());
        h.pop();


        mark[v] = 1;

        for(int i = 0; i < mat[v].size(); i++){
            w = mat[v][i].first;
            p = mat[v][i].second;
            if(mark[w] == 0 && dist[w] > dist[v] + p){
                dist[w] = dist[v] + p;
                h.emplace(dist[w], w, p);
            }
        }
    }

    return true;
}

//belmond-ford: 
vector<int> dist(V, INF); dist[s] = 0; //s = inicio da trevessia do grafo
for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times
  for (int u = 0; u < V; u++) // these two loops = O(E), overall O(VE)
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      int v = AdjList[u][j]; // record SP spanning here if needed
      dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
    }

//Achar ciclo negativo
bool hasNegativeCycle = false;
for (int u = 0; u < V; u++) // one more pass to check
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dist[v.first] > dist[u] + v.second) // if this is still possible
      hasNegativeCycle = true; // then negative cycle exists!
    }

//floy-warshall
// precondition: AdjMat[i][j] contains the weight of edge (i, j)
// or INF (1B) if there is no such edge
// AdjMat is a 32-bit signed integer array
//k = linha, i = coluna, j = as permutações
for (int k = 0; k < V; k++) // remember that loop order is k->i->j
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++) //o objetivo do código vem nessa parte
      AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]); //menor valor entre 2 vértices diretamente ou por outros vértices

//Printar o caminho com floyd-warshall
// if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
// AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
// p[i][j] = p[k][j]; // update the parent matrix
// }
// for (int i = 0; i < V; i++)
// for (int j = 0; j < V; j++)
// p[i][j] = i;

//Saber se a conexão entre 2 é direta ou não
// AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);

//Solução para o problema minmax de grafo
// AdjMat[i][j] = min(AdjMat[i][j], max(AdjMat[i][k], AdjMat[k][j]));

//Diâmetro de grafo: roda o de menor caminho e acha o maior valor na matriz
