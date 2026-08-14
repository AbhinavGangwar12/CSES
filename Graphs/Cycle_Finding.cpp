#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


const long long INF = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<long long>> edges;
    for(int i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    int cycleNode = -1;
    for(int i = 0; i<n; i++){
        cycleNode = -1;
        for(auto edge: edges){
            long long u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] < INF && dist[u] + w < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + w;
                cycleNode = v;
            }
        }
    }
    if(cycleNode == -1){
        cout << "NO\n";
    }
    else{
        for(int i = 0; i<n; i++){
            cycleNode = parent[cycleNode];
        }
        vector<int> cycle;
        for(int v = cycleNode; ; v = parent[v]){
            cycle.push_back(v);
            if(v == cycleNode && cycle.size() > 1){
                break;
            }
        }
        cout << "YES\n";
        reverse(cycle.begin(), cycle.end());
        for(int v : cycle){
            cout<< v << " ";
        }
    }
    return 0;
}