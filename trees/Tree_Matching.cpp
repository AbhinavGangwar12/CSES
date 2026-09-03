#include<iostream>
#include<vector>

using namespace std;

void dfs(const vector<vector<int>> &adj, vector<int> &matched, int u, int p, int &ans){
    for(int v : adj[u]){
        if(v != p){
            dfs(adj, matched, v, u, ans);
            if(!matched[u] && !matched[v]){
                matched[u] = true;
                matched[v] = true;
                ans++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))return 0;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> matched(n, 0);
    int ans = 0;
    dfs(adj, matched, 0, -1, ans);
    cout<<ans<<"\n";
    return 0;
}