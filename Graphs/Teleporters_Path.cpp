#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> adj(n);
    vector<int> in_deg(n, 0), out_deg(n, 0);
    vector<int> head(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        out_deg[u]++;
        in_deg[v]++;
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (out_deg[i] - in_deg[i] != 1) possible = false;
        } else if (i == n - 1) {
            if (in_deg[i] - out_deg[i] != 1) possible = false;
        } else {
            if (in_deg[i] != out_deg[i]) possible = false;
        }
    }
    
    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> st;
    vector<int> path;
    st.push_back(0);
    
    while (!st.empty()) {
        int u = st.back();
        if (head[u] < adj[u].size()) {
            int v = adj[u][head[u]++];
            st.push_back(v);
        } else {
            path.push_back(u);
            st.pop_back();
        }
    }
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1 << (i == 0 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}