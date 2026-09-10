#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MAXN = 2e5;
const int LOGN = 19;
vector<int> adj[MAXN];
int up[MAXN][LOGN], depth[MAXN];

void dfs(int u, int p){
    up[u][0] = p;
    depth[u] = depth[p] + 1;
    for(int i = 1; i < LOGN; i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int v : adj[u]){
        if(v != p){
            dfs(v,u);
        }
    }
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    int diff = depth[a] - depth[b];
    for(int i = LOGN-1; i >= 0; i--){
        if((diff >> i) & 1){
            a = up[a][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = LOGN - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int dist(int a, int b){
    int lca = get_lca(a, b);
    return depth[a] + depth[b] - 2 * depth[lca];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1, 1);
    // for(int i = 1; i <= n; i++){
    //     cout<<depth[i]<<" ";
    // }
    cout<<endl;
    while(m--){
        int a, b;
        cin >> a >> b;
        cout<<dist(a, b)<<"\n";
    }
    return 0;
}