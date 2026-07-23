#include <iostream>
#include<algorithm>
#include <vector>
#include<queue>
#include<set>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    bool directed;
    bool weighted;

    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices, bool directed = false, bool weighted = false) {
        V = vertices;
        this->directed = directed;
        this->weighted = weighted;

        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back({v, w});

        if (!directed)
            adj[v].push_back({u, w});
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";

            for (auto edge : adj[i]) {
                if (weighted)
                    cout << "(" << edge.first << "," << edge.second << ") ";
                else
                    cout << edge.first << " ";
            }

            cout << '\n';
        }
    }

    vector<vector<pair<int, int>>>& getAdjList() {
        return adj;
    }
};

class GraphMatrix {
private:
    int V;
    bool directed;
    bool weighted;

    vector<vector<int>> mat;

public:
    GraphMatrix(int vertices,
                bool directed = false,
                bool weighted = false) {

        V = vertices;
        this->directed = directed;
        this->weighted = weighted;

        mat.assign(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w = 1) {
        mat[u][v] = weighted ? w : 1;

        if (!directed)
            mat[v][u] = weighted ? w : 1;
    }

    void printMatrix() {
        for (auto &row : mat) {
            for (int x : row)
                cout << x << " ";
            cout << '\n';
        }
    }

    vector<vector<int>>& getMatrix() {
        return mat;
    }
};

class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i<n ;i++){
                parent[i] = i;
            }
        }
        int UParent(int x){
            if(parent[x] != x){
                return parent[x] = UParent(parent[x]);
            }
            return parent[x];
        }
        void Union(int x, int y){
            int px = UParent(x);
            int py = UParent(y);
            if(px == py) return;
            if(rank[px] < rank[py]){
                parent[px] = py;
            }
            else if(rank[px] > rank[py]){
                parent[py] = px;
            }
            else{
                parent[py] = px;
                rank[px]++;
            }
        }
};

void dfs_list(const vector<vector<pair<int,int>>> &adj, vector<bool> &vis, int curr){
    vis[curr] = true;
    cout << curr << " ";

    for(const auto &edge : adj[curr]){
        int neighbour = edge.first;
        if(!vis[neighbour]){
            dfs_list(adj, vis, neighbour);
        }
    }
}


void dfs_mat(const vector<vector<int>> &adj, vector<bool> &vis, int curr){
    vis[curr] = 1;
    cout<<curr<<" ";
    int size = adj.size();
    for(int neighbour = 0; neighbour < size; neighbour++){
        if(adj[curr][neighbour] && !vis[neighbour]){
            dfs_mat(adj, vis, neighbour);
        }
    }
    return;
}

void bfs(const vector<vector<pair<int,int>>> &adj, int src){
    vector<bool> vis(adj.size(), false);
    queue<int> q;

    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for(const auto &edge : adj[curr]){
            int neighbour = edge.first;

            if(!vis[neighbour]){
                vis[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

void bfs_mat(const vector<vector<int>> &adj, int src){
    vector<bool> vis(adj.size(), 0);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int curr = q.front();q.pop();
        cout<<curr<<" ";
        int size = adj.size();
        for(int n = 0; n < size; n++){
            if(!vis[n] && adj[curr][n]){
                q.push(n);
                vis[n] = 1;
            }
        }
    }
    return;
}

vector<int> dijkstra_h(const vector<vector<pair<int,int>>> &edges, int src){
    int V = edges.size();

    vector<int> dist(V, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > q;

    dist[src] = 0;
    q.push({0, src});

    while(!q.empty()){
        auto top = q.top();
        q.pop();

        int w = top.first;
        int node = top.second;

        if(w > dist[node])
            continue;

        for(const auto &neighbor : edges[node]){
            int n = neighbor.first;
            int dw = w + neighbor.second;

            if(dw < dist[n]){
                dist[n] = dw;
                q.push({dw, n});
            }
        }
    }

    return dist;
}


vector<int> dijkstra_s(const vector<vector<pair<int,int>>> &edges, int src){
    int V = edges.size();

    vector<int> dist(V, INT_MAX);

    set<pair<int,int>> s;

    dist[src] = 0;
    s.insert({0, src});

    while(!s.empty()){
        auto top = *(s.begin());
        int w = top.first;
        int node = top.second;
        s.erase(s.begin());
        if(w > dist[node])
            continue;

        for(const auto &neighbor : edges[node]){
            int n = neighbor.first;
            int dw = w + neighbor.second;

            if(dw < dist[n]){
            if(dist[n] != INT_MAX){
                s.erase({dist[n], n});
            }
        
            dist[n] = dw;
            s.insert({dist[n], n});
        }

        }
    }

    return dist;
}


vector<int> bellmanFord(const vector<vector<int>> &edges, int V, int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 1; i < V; i++){
        bool updated = false;
        for(const auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                updated = true;
            }
        }

        if(!updated)
            break;
    }

    for(const auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout << "Negative cycle detected!" << endl;
            return {-1};
        }
    }

    return dist;
}

// MST 
// prims algorithm: time complexity: O((E + V) log V), space complexity: O(V)
int prims(const vector<vector<pair<int,int>>> &edges, int src){
    int V = edges.size();
    vector<bool> vis(V, false);
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> q;

    q.push({0, src});
    int res = 0;
    int added = 0;

    while(!q.empty() && added < V){
        auto top = q.top();
        q.pop();
        int w = top.first;
        int node = top.second;

        if(vis[node])
            continue;

        res += w;
        vis[node] = true;
        added++;

        for(const auto &neighbor : edges[node]){
            int n = neighbor.first;
            int dw = neighbor.second;
            if(!vis[n]){
                q.push({dw, n});
            }
        }
    }

    return added == V ? res : -1;
}

// kruskal's algorithm: time complexity: O(E log E), space complexity: O(V)
int kruskal(const vector<vector<pair<int,int>>> &edges, int V){
    vector<tuple<int,int,int>> edgeList;
    // O(N + E)
    for(int u = 0; u < V; u++){
        for(const auto &neighbor : edges[u]){
            int v = neighbor.first;
            int w = neighbor.second;

            if(u < v)edgeList.push_back({w, u ,v});
        }
    }
    // O(E log E)
    sort(edgeList.begin(), edgeList.end());
    int res = 0;
    DSU dsu(V);
    for(const auto &edge : edgeList){
        int u = get<1>(edge);
        int v = get<2>(edge);
        int w = get<0>(edge);
        if(dsu.UParent(u) != dsu.UParent(v)){
            dsu.Union(u,v);
            res += w;
        }
    }
    return res;

}

int main() {

    int V, E;
    cin >> V >> E;

    Graph g(V, false, true);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    vector<bool> vis(V, false);

    dfs_list(g.getAdjList(), vis, 0);

    cout << '\n';

    bfs(g.getAdjList(), 0);


    return 0;
}
