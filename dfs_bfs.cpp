void DFS(vector<vector<int>>& adj, vector<bool>& mark, int v) {
    cout << v << " ";
    mark[v] = true;
    for(int i : adj[v]) {
        if(mark[i] == false) {
            DFS(adj, mark, i);
        }
    }
}

void toposort(vector<vector<int>>& adj, vector<bool>& mark, int v, stack<int>& topo) {
    mark[v] = true;
    for(int i : adj[v]) {
        if(mark[i] == false) {
            toposort(adj, mark, i, topo);
        }
    }
    topo.push(v);
}

void BFS(vector<vector<int>>& adj, vector<bool>& mark, int start) {
    queue<int> queue_bfs;
    queue_bfs.push(start);
    mark[start] = true;
    while(queue_bfs.size() > 0) {
        int v = queue_bfs.front(); queue_bfs.pop();
        cout << v << " ";
        for(int x : adj[v]) {
            if(mark[x] == false) {
                mark[x] = true;
                queue_bfs.push(x);
            }
        }
    }
}

void graphTraverse(vector<vector<int>>& adj) {
    vector<bool> mark(adj.size(), false);
    for(int i = 0; i < adj.size(); i++) {
        if(mark[i] == false) {
            BFS(adj, mark, i);
        }
    }
}


//Ponto de articulação
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED) { // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true; // store this information first
            if (dfs_low[v.first] > dfs_num[u]) // for bridge
                printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // update dfs_low[u]
        }
        else if (v.first != dfs_parent[u]) // a back edge and not direct cycle
        dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }// update dfs_low[u]
 }
// inside int main()
int main(){
    dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
    dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
    printf("Bridges:\n");
    for (int i = 0; i < V; i++){
        if (dfs_num[i] == UNVISITED) {
            dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); 
        }
    }
}

//Strongly conected
vector<int> dfs_num, dfs_low, S, visited; // global variables
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
            tarjanSCC(v.first);
        if (visited[v.first]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); }
        if (dfs_low[u] == dfs_num[u]) {// if this is a root (start) of an SCC
            printf("SCC %d:", ++numSCC);
        }// this part is done after recursion
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            printf(" %d", v);
            if (u == v) break;
        }
        printf("\n");
    }
}
// inside int main()
dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
dfsNumberCounter = numSCC = 0;
for (int i = 0; i < V; i++)
if (dfs_num[i] == UNVISITED)
tarjanSCC(i);
