#include <iostream>
#include <vector>

using namespace std;
int dfs(int u, int p, const vector<vector<int>> &adj, vector<int> &sub) {
    int count = 0;
    for (int v : adj[u]) {
        if (v != p) {
            count += 1 + dfs(v, u, adj, sub);
        }
    }
    sub[u] = count;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    vector<int> sub(n + 1, 0);
    dfs(1, 0, adj, sub);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}