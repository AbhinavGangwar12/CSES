#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int LOG = 20; // 2^19 > 200,000

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> t(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> up(n + 1, vector<int>(LOG));
    vector<vector<int>> adj_rev(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        up[i][0] = t[i];
        indegree[t[i]]++;
        adj_rev[t[i]].push_back(i); // Reverse edges for BFS depth
    }

    // 1. Build Binary Lifting Table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    // Helper lambda to jump 'steps' forward from 'node' in O(log steps)
    auto advance = [&](int node, int steps) {
        for (int j = 0; j < LOG; j++) {
            if ((steps >> j) & 1) {
                node = up[node][j];
            }
        }
        return node;
    };

    // 2. Kahn's Algorithm: Strip away tree nodes to find cycle nodes
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        indegree[t[u]]--;
        if (indegree[t[u]] == 0) {
            Q.push(t[u]);
        }
    }

    // 3. Map the Cycles (Nodes with remaining indegree > 0 are in cycles)
    vector<bool> in_cycle(n + 1, false);
    vector<int> cycle_id(n + 1, 0);
    vector<int> pos(n + 1, 0);
    vector<int> cycle_len;
    cycle_len.push_back(0); // 1-based indexing for cycle IDs

    int current_cid = 1;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] > 0 && !in_cycle[i]) {
            int curr = i;
            int idx = 0;
            while (!in_cycle[curr]) {
                in_cycle[curr] = true;
                cycle_id[curr] = current_cid;
                pos[curr] = idx++;
                curr = t[curr];
            }
            cycle_len.push_back(idx);
            current_cid++;
        }
    }

    // 4. Reverse BFS to calculate depths of tree nodes
    vector<int> depth(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (in_cycle[i]) {
            Q.push(i); // Start BFS shockwave from all cycle nodes
        }
    }

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : adj_rev[u]) {
            if (!in_cycle[v]) { // Move upstream into trees
                depth[v] = depth[u] + 1;
                Q.push(v);
            }
        }
    }

    // 5. Answer Queries
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (!in_cycle[b]) {
            // Case 1: Target b is NOT in a cycle
            if (depth[a] >= depth[b]) {
                int dist = depth[a] - depth[b];
                if (advance(a, dist) == b) {
                    cout << dist << "\n";
                    continue;
                }
            }
            cout << -1 << "\n";
        } else {
            // Case 2: Target b IS in a cycle
            int root = advance(a, depth[a]); // Jump to cycle entry point
            
            if (cycle_id[root] != cycle_id[b]) {
                cout << -1 << "\n"; // Different cycle components
            } else {
                int len = cycle_len[cycle_id[root]];
                int cycle_dist = (pos[b] - pos[root] + len) % len;
                cout << depth[a] + cycle_dist << "\n";
            }
        }
    }

    return 0;
}