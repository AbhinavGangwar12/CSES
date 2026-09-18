#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
long long val[MAXN];
long long bit[MAXN];
int in[MAXN], out[MAXN];
int timer = 0;
int n, q;

// Standard Fenwick Tree point update
void bit_update(int idx, long long delta) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

// Difference array logic for range update [l, r]
void range_update(int l, int r, long long delta) {
    bit_update(l, delta);
    bit_update(r + 1, -delta);
}

// Point query: prefix sum up to idx
long long point_query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void dfs(int u, int p) {
    in[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = timer;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 1. Flatten the tree to record entry (in) and exit (out) times
    dfs(1, 0);

    // 2. Initialize BIT with initial node values
    for (int i = 1; i <= n; i++) {
        range_update(in[i], out[i], val[i]);
    }

    // 3. Process Queries
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            long long v;
            cin >> u >> v;
            long long diff = v - val[u];
            val[u] = v;
            range_update(in[u], out[u], diff);
        } else {
            int u;
            cin >> u;
            cout << point_query(in[u]) << "\n";
        }
    }

    return 0;
}