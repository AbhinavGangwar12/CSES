#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const long long INF = 1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<pair<int, long long>>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
    }
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 0});
    
    vector<long long> dist(n, INF);
    dist[0] = 0;
    
    while(!q.empty()){
        auto [w, u] = q.top();
        q.pop();
        

        if(w > dist[u]) continue;
        
        for(auto neighbor: adj[u]){
            int v = neighbor.first;
            long long weight = neighbor.second;
            
            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                q.push({dist[v], v});
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    
    return 0;
}