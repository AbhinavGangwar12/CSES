#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>>& edges, vector<bool>& visited, vector<int>& topo, int u){
    visited[u] = true;
    for(auto v : edges[u]){
        if(!visited[v]){
            dfs(edges, visited, topo, v);
        }
    }
    topo.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges[u-1].push_back(v-1);
    }
    vector<int> topo;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(edges, visited, topo, i);
        }
    }
    reverse(topo.begin(), topo.end());
    vector<int> dist(n , -1);
    vector<int> parent(n, -1);

    dist[0] = 1;
    for(int u : topo){
        if(dist[u] != -1){
            for(int v : edges[u]){
                if(dist[v] < dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                }
            }
        }
    }
    if(dist[n-1] == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    for(int v = n-1; v != -1; v = parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout<<path.size()<<"\n";
    for(int v : path){
        cout<<v+1<<" ";
    }
    cout<<"\n";
    return 0;
}