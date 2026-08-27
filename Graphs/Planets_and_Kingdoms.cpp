// KOSARAJU'S ALGORITHM IMPLEMENTATION

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order){
    visited[node]=true;
    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor, adj, visited, order);
        }
    }
    order.push_back(node);
}

void dfs2(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component, int comp_id){
    visited[node]=true;
    component[node]=comp_id;
    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            dfs2(neighbor, adj, visited, component, comp_id);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) {
        cerr << "Error reading input." << endl;
        return 1;
    }
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        if(!(cin >> u >> v)) {
            cerr << "Error reading edge input." << endl;
            return 1;
        }
        u--; v--;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<int> order;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, order);
        }
    }
    fill(visited.begin(), visited.end(), false);
    reverse(order.begin(), order.end());
    vector<int> component(n, -1);
    int comp_id = 1;
    for(int node : order){
        if(!visited[node]){
            dfs2(node, rev_adj, visited, component, comp_id);
            comp_id++;
        }
    }
    cout<<comp_id-1<<endl;
    for(int i = 0; i < n; i++){
        cout << component[i] << " ";
    }
    cout<<endl;
    return 0;
}