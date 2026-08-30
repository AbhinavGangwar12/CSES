#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs1(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order){
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs1(v, adj, visited, order);
        }
    }
    order.push_back(u);
}

void dfs2(int u, const vector<vector<int>>& adj_rev, vector<int>& ssc, const vector<long long>& coins, int current_scc, long long &total_coins_in_scc){
    ssc[u] = current_scc;
    total_coins_in_scc += coins[u];
    for(int v: adj_rev[u]){
        if(ssc[v] == -1){
            dfs2(v, adj_rev, ssc, coins, current_scc, total_coins_in_scc);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if(!(cin >> n >> m)) return 0;
    
    vector<vector<int>> adj(n), adj_rev(n);
    vector<long long> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    vector<int> order;
    
    for(int i = 0 ; i < n; i++){
        if(!visited[i]){
            dfs1(i, adj, visited, order);
        }
    }
    
    vector<int> ssc(n, -1);
    vector<long long> ssc_coins;
    int current_scc = 0;
    
    for(int i = n - 1; i >= 0; i--){
        int u = order[i];
        if(ssc[u] == -1){
            long long total_coins_in_scc = 0; // Changed to long long
            dfs2(u, adj_rev, ssc, coins, current_scc, total_coins_in_scc);
            ssc_coins.push_back(total_coins_in_scc);
            current_scc++;
        }
    }
    
    vector<vector<int>> dag(current_scc);
    for(int u = 0; u < n; u++){
        for(int v: adj[u]){
            if(ssc[u] != ssc[v]){
                dag[ssc[u]].push_back(ssc[v]);
            }
        }
    }
    
    vector<long long> dp(current_scc, 0);
    long long max_total = 0;
    for(int i = current_scc - 1; i >= 0; i--){
        dp[i] = ssc_coins[i];
        for(int v : dag[i]){
            dp[i] = max(dp[i], ssc_coins[i] + dp[v]);
        }
        max_total = max(max_total, dp[i]);
    }
    
    cout << max_total << "\n";
    return 0;
}