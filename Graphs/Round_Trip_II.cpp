#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>> &edges, vector<int> &state, vector<int> &parent, int u, int &cycle_start, int &cycle_end) {
    state[u] = 1;
    
    for (auto v : edges[u]) {
        if (state[v] == 0) {
            parent[v] = u;
            if (dfs(edges, state, parent, v, cycle_start, cycle_end)) {
                return true;
            }
        } 
        else if (state[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    
    state[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
    }
    
    vector<int> state(n, 0);
    vector<int> parent(n, -1);
    int cycle_start = -1, cycle_end = -1;
    
    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (dfs(edges, state, parent, i, cycle_start, cycle_end)) {
                break;
            }
        }
    }
    
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    cout<<cycle.size()<<"\n";
    for (int i = cycle.size() - 1; i >= 0; i--) {
        cout << cycle[i] + 1 << " ";
    }
    cout << "\n";
    
    return 0;
}