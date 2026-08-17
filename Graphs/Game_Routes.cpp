#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(const vector<vector<int>> &edges, vector<bool> &visited, vector<int> &topo, int u){
    visited[u] = true;
    for(auto v : edges[u]){
        if(!visited[v]){
            dfs(edges, visited, topo, v);
        }
    }
    topo.push_back(u);
}
const int MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        edges[u].push_back(v);
    }
    vector<bool> visited(n, false);
    vector<int> topo;
    for(int i = 0 ; i < n; i++){
        if(!visited[i]){
            dfs(edges, visited, topo,i);
        }
    }
    reverse(topo.begin(), topo.end());
    vector<int> ways(n, 0);
    ways[0] = 1;
    for(int u : topo){
        if(ways[u] != -1){
            for(int v : edges[u]){
                ways[v] = ( ways[u] + ways[v] ) % MOD;
                // if(ways[u] + 1 > ways[v]){
                // }
            }
        }
    }
    cout<<ways[n-1]<<"\n";
    return 0;
}