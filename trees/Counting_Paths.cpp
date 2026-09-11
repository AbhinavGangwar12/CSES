#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 2e5+5;
const int LOGN = 19;
vector<int> adj[MAXN];
int depth[MAXN], up[MAXN][LOGN], v[MAXN], ans[MAXN];
int n;

void dfs(int u, int p, int d = 0){
    depth[u] = d;
    up[u][0] = p;
    for(int i = 1; i < LOGN; i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int v : adj[u]){
        if(v != p){
            dfs(v,u, d+1);
        }
    }
}

int get_lcs(int a, int b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for(int i = LOGN - 1; i >= 0; i--){
        if((diff >> i) & 1){
            a = up[a][i];
        }
    }
    if(a == b)return a;
    for(int i = LOGN - 1; i>=0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void dfs_sum(int u, int p){
    ans[u] = v[u];
    for(int v : adj[u]){
        if(v != p){
            dfs_sum(v, u);
            ans[u] += ans[v];
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    if(!(cin >> n >> q))return 0;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while(q--){
        int a,b;
        cin >> a >> b;
        int lcs = get_lcs(a, b);
        v[a]++;v[b]++;
        v[lcs]--;v[up[lcs][0]]--;
    }
    dfs_sum(1, 0);
    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}