#include <iostream>
#include <vector>

using namespace std;

// Global variables for the graph and Kosaraju's algorithm
vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order;
vector<int> scc_id;

// Helper to convert input into our 0-indexed node system
int getNode(char sign, int x) {
    int base_node = 2 * (x - 1);
    return (sign == '+') ? base_node : base_node + 1;
}

// Pass 1: standard DFS to establish processing order
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.push_back(u); // Push to list AFTER children are explored
}

// Pass 2: DFS on reversed graph to assign SCC IDs
void dfs2(int u, int current_scc) {
    scc_id[u] = current_scc;
    for (int v : adj_rev[u]) {
        // If it hasn't been assigned an SCC yet
        if (scc_id[v] == 0) { 
            dfs2(v, current_scc);
        }
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    int total_nodes = 2 * m;
    adj.assign(total_nodes, vector<int>());
    adj_rev.assign(total_nodes, vector<int>());

    // Build the implication graph
    for (int i = 0; i < n; i++) {
        char sign1, sign2;
        int x1, x2;
        cin >> sign1 >> x1 >> sign2 >> x2;

        int u = getNode(sign1, x1);
        int v = getNode(sign2, x2);
        int not_u = u ^ 1;
        int not_v = v ^ 1;

        adj[not_u].push_back(v);
        adj_rev[v].push_back(not_u);

        adj[not_v].push_back(u);
        adj_rev[u].push_back(not_v);
    }

    // Step 1 of Kosaraju: Get exit order
    visited.assign(total_nodes, false);
    for (int i = 0; i < total_nodes; i++) {
        if (!visited[i]) dfs1(i);
    }

    // Step 2 of Kosaraju: Assign SCCs
    scc_id.assign(total_nodes, 0);
    int current_scc = 1;
    // Iterate through the order array backwards
    for (int i = total_nodes - 1; i >= 0; i--) {
        int u = order[i];
        if (scc_id[u] == 0) {
            dfs2(u, current_scc);
            current_scc++;
        }
    }

    // Step 3: Check for contradictions and build the solution
    string result = "";
    for (int i = 1; i <= m; i++) {
        int pos_node = getNode('+', i);
        int neg_node = getNode('-', i);

        // If +x and -x are in the same SCC, it's impossible
        if (scc_id[pos_node] == scc_id[neg_node]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        // 2-SAT Assignment Trick:
        // Kosaraju's algorithm processes sources first. So higher SCC IDs 
        // represent sinks (nodes that don't force further contradictory chains).
        // We always choose the node with the higher SCC ID.
        if (scc_id[pos_node] > scc_id[neg_node]) {
            result += "+ ";
        } else {
            result += "- ";
        }
    }

    cout << result << "\n";
    return 0;
}