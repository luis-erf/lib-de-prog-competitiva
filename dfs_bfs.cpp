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
