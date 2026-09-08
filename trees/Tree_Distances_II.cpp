#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 2e5+5;
vector<vector<int>> adj(MAXN);
long long subtree_dist[MAXN], subtree_size[MAXN], ans[MAXN];
int n;

void dfs1(int u, int parent){
    subtree_dist[u] = 0;
    subtree_size[u] = 1;
    for(int v : adj[u]){
        if(v != parent){
            dfs1(v, u);
            subtree_size[u] += subtree_size[v];
            subtree_dist[u] += subtree_dist[v] + subtree_size[v];
        }
    }
    return;
}

void dfs2(int u, int parent){
    for(int v : adj[u]){
        if(v != parent){
            ans[v] = ans[u] - subtree_size[v] + (n - subtree_size[v]);
            dfs2(v, u);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(!(cin >> n))return 0;
    for(int i = 0 ; i < n-1 ; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    ans[0] = subtree_dist[0];
    dfs2(0, -1);
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}