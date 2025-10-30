class DSU {
    private:
        vector<int> parents;
        vector<int> sizes;
    public:
        DSU(int size) {
            parents.resize(size); sizes.resize(size, 1);
            for(int i = 0; i < size; ++i) {
                parents[i] = i;
            }
        }

        int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

        void unite(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if(x_root == y_root) { return; }

            if(sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
            sizes[x_root] += sizes[y_root];
		    parents[y_root] = x_root;
        }

        bool connected(int x, int y) { return find(x) == find(y); }
};

void kruskal(vector<vector<pair<int, int>>>& graph) {
    DSU dsu(graph.size());
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    vector<vector<bool>> added(graph.size(), vector<bool>(graph.size(), false));
    
    for(int i = 0; i < graph.size(); i++) {
        for(auto [v, w] : graph[i]) {
            if(!added[i][v]) {
                heap.push(make_tuple(w, i, v));
                added[i][v] = added[v][i] = true;
            }
        }
    }

    vector<tuple<int, int, int>> ds;
    int numMST = graph.size();
    while(!heap.empty() && numMST > 1) {
        int weight = get<0>(heap.top());
        int a = get<1>(heap.top());
        int b = get<2>(heap.top()); heap.pop();

        if(!dsu.connected(a, b)) {
            dsu.unite(a, b);
            ds.emplace_back(weight, a, b);
            numMST--;
        }
    }

    cout << "Arestas da Árvore Geradora Mínima:\n";
    for (auto [w, u, v] : ds) {
        cout << u << " - " << v << " (peso " << w << ")\n";
    }
}

void prim(vector<vector<pair<int, int>>>& graph) {
    priority_queue<ti, vector<ti>, greater<ti>> heap;
    vector<int> distances(graph.size(), INT_MAX);
    vector<bool> marked(graph.size(), false);
    vector<int> vertices(graph.size(), -1);
    vector<int> ord;
    heap.push(make_tuple(0, 0, 0)); distances[0] = 0;
    for(int i = 0; i < graph.size(); i++) {
        int p = -1, v = -1;
        do {
            if(heap.empty()) { return; }
            v = get<1>(heap.top());
            p = get<2>(heap.top());
            heap.pop();
        } while(marked[v]);
        
        marked[v] = true; vertices[v] = p;
        ord.push_back(v);
        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > weight) {
                distances[w] = weight;
                heap.push(make_tuple(distances[w], w, v));
            }
        } 
    }
    for(int pp : ord) {
        cout << pp << " ";
    }
    cout << "\n";
}
