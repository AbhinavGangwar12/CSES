#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MAXN = 200005;
const int LOGN = 19;
vector<int> adj[MAXN];
int up[MAXN][LOGN], depth[MAXN];

void dfs(int u, int p){
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for(int i = 1; i<LOGN;i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(int v : adj[u]){
        if(v != p)
            dfs(v, u);
    }
    return;
}
int lcs(int a, int b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for(int j = LOGN - 1; j >= 0; j--){
        if((diff >> j) & 1){
            a = up[a][j];
        }
    }
    if(a == b)return a;
    for(int i = LOGN-1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    if(!(cin >> n >> m))return 0;
    for(int i = 2; i <= n; i++){
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    dfs(1, 1);
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << lcs(a, b)<<"\n";
    }
    return 0;
}