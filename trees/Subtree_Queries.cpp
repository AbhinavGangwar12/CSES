#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
long long val[MAXN];
int in_time[MAXN], out_time[MAXN];
long long bit[MAXN];
int timer = 0;
int n, q;

void bit_update(int idx, long long delta) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

long long bit_query(int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void dfs(int u, int p) {
    in_time[u] = ++timer;
    bit_update(in_time[u], val[u]);
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out_time[u] = timer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            long long diff = x - val[s];
            val[s] = x;
            bit_update(in_time[s], diff);
        } else {
            int s;
            cin >> s;
            long long ans = bit_query(out_time[s]) - bit_query(in_time[s] - 1);
            cout << ans << "\n";
        }
    }

    return 0;
}
