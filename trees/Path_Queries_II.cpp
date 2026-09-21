#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int in_time[MAXN], out_time[MAXN];
long long bit[MAXN], val[MAXN];
int timer = 0;
int n, q;

void dfs(int u, int p){
    in_time[u] = ++timer;
    for(int v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    out_time[u] = timer;
}

void bit_update(int idx, int val){
    long long cmax = INT_MIN;
    for(; idx <= n; idx += idx & -idx){
        bit[idx] = max(cmax, bit[idx]);
    }
}

long long point_query(int idx){
    long long cmax = 0;
    for(; idx >= 0; idx -= idx & -idx){
        cmax = max(cmax, bit[idx]);
    }
    return cmax;
}

void range_update(int l, int r, int new_val){
    bit_update(l, new_val);
    bit_update(r+1, -new_val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(!(cin >> n >> q))return 0;
    for(int i = 1; i <= n ; i++){
        cin >> val[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            val[u] = v;
            range_update(in_time[u], out_time[u], v);
        }
        else{
            int u, v;
            cin >> u >> v;
            cout
        }
    }
    return 0;
}