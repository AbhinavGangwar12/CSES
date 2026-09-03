#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 20;
const int MAXM = 400;
const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(MAXN);
    vector<int> in_deg(MAXN, 0), out_deg(MAXN, 0);
    vector<int> head(MAXN, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        out_deg[u]++;
        in_deg[v]++;
    }
    bool possible = true;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(out_deg[i] - in_deg[i] != 1) possible = false;
        } else if(i == n-1){
            if(in_deg[i] - out_deg[i] != 1) possible = false;
        } else {
            if(in_deg[i] != out_deg[i]) possible = false;
        }
    }
    if(!possible){
        cout << 0;
        return 0;
    }
    vector<int> st;
    int counter = 0;
    st.push_back(0);
    while(!st.empty()){
        int u = st.back();
        if(head[u] < adj[u].size()){
            int v = adj[u][head[u]++];
            st.push_back(v);
        } else {
            counter++;
            st.pop_back();
        }
    }
    if(counter != m + 1){
        cout << 0;
        return 0;
    }
    int max_deg = 0;
    for(int i = 0; i < n; i++){
        max_deg = max(max_deg, out_deg[i]);
    }
    cout << max_deg;
    return 0;
}