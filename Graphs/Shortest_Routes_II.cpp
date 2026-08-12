#include<iostream>
#include<vector>

using namespace std;
const long long INF = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    int n, m, q;
    if(!(cin >> n >> m >> q)) return 0;
    vector<vector<long long>> edges(n, vector<long long>(n, INF));
    vector<pair<int, int>> queries(q);
    for(int i = 0; i < n; i++){
        edges[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        edges[u][v] = min(edges[u][v], w);
        edges[v][u] = min(edges[v][u], w);
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries[i] = {a-1, b-1};
    }
    // Floyd-Warshall algorithm to compute shortest paths
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(edges[i][k] < INF && edges[k][j] < INF){
                    edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a = queries[i].first;
        int b = queries[i].second;
        if(edges[a][b] < INF){
            cout << edges[a][b] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}