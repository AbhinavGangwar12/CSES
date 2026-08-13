#include <iostream>
#include <vector>

using namespace std;

const long long NINF = -1e17; 
const long long PINF = 1e17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<long long>> edges(m, vector<long long>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    vector<long long> dist(n + 1, NINF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        bool updated = false;
        for (const auto& edge : edges) {
            long long u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != NINF && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (int i = 1; i <= n; i++) {
        for (const auto& edge : edges) {
            long long u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != NINF) {
                if (dist[u] + w > dist[v] || dist[u] == PINF) {
                    dist[v] = PINF;
                }
            }
        }
    }

    if (dist[n] == PINF) {
        cout << "-1\n";
    } else {
        cout << dist[n] << "\n";
    }

    return 0;
}