#include<iostream>
#include<vector>

using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node] = true;
    for(int child: adj[node]){
        if(!visited[child]){
            dfs(child, adj, visited);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        if(!(cin >> u >> v))return 0;
        adj[u-1].push_back(v-1);
        rev_adj[v-1].push_back(u-1);
    }
    vector<bool> visited(n, false);
    vector<int> kingdoms(n, -1);
    int kingdom_id = 1;
    for(int i = 0; i < n; i++){
        if(visited[i])continue;
        vector<bool> v1(n, false);
        vector<bool> v2(n, false);
        dfs(i, adj, v1);
        dfs(i, rev_adj, v2);
        for(int j = 0; j < n; j++){
            if(v1[j] && v2[j]){
                visited[j] = true;
                kingdoms[j] = kingdom_id;
            }
        }
        kingdom_id++;
    }
    cout<<kingdom_id-1<<"\n";
    for(int i = 0; i < n; i++){
        cout<<kingdoms[i]<<" ";
    }
    cout<<"\n";
    return 0;
}