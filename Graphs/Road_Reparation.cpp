// #include<iostream>
// #include<vector>
// #include<queue>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m;
//     if(!(cin >> n >> m))return 0;
//     vector<vector<pair<int,int>>> adj(n);
//     for(int i = 0; i < m; i++){
//         int u, v, w;
//         if(!(cin >> u >> v >> w))return 0;
//         u--; v--;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
//     vector<bool> visited(n, false);
//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//     pq.push({0,0});
//     long long tot_cost = 0;
//     int edges_used = 0;
//     while(!pq.empty()){
//         auto [cost, u] = pq.top();
//         pq.pop();
//         if(visited[u]) continue;
//         visited[u] = true;
//         edges_used++;
//         tot_cost += cost;
//         for(auto [v, w] : adj[u]){
//             if(!visited[v]){
//                 pq.push({w, v});
//             }
//         }
//     }
//     if(edges_used != n){
//         cout << "IMPOSSIBLE\n";
//     }
//     else{
//         cout << tot_cost << "\n";
//     }
//     return 0;
// }



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DSU{
    private:
        vector<int> parent, rank;
    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n ;i++){
                parent[i] = i;
            }
        }
        int UParent(int x){
            if(parent[x] != x){
                return parent[x] = UParent(parent[x]);
            }
            return parent[x];
        }
        bool Union(int x, int y){
            int px = this->UParent(x);
            int py = this->UParent(y);
            if(px == py)return false;
            if(rank[px] < rank[py]){
                parent[px] = py;
                return true;
            }
            else if(rank[px] > rank[py]){
                parent[py] = px;
                return true;
            }
            
                parent[py] = px;
                rank[px]++;
                return true;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        if(!(cin >> u >> v >> w))return 0;
        u--; v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long res = 0;
    int added = 0;
    for(int i = 0; i < m; i++){
        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        if(dsu.Union(u, v)){
            res += w;
            added++;
        }
    }
    if(added != n - 1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << res << "\n";
    }
    return 0;
}