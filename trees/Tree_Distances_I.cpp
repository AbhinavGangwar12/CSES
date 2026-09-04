#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

pair<int,int> bfs(const int &n, const vector<vector<int>> &adj, const int &start, vector<int> &dist){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest_node = start;
    int max_distance = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(dist[node] > max_distance){
            max_distance = dist[node];
            farthest_node = node;
        }
        for(int neighbor : adj[node]){
            if(dist[neighbor] == -1){
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return {farthest_node, max_distance};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    if(!(cin >> n)) return 0;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n, -1);
    auto [farthest_node, dump] = bfs(n, adj, 0, dist);
    fill(dist.begin(), dist.end(), -1);
    auto [farthest_node1, diameter] = bfs(n, adj, farthest_node, dist);
    vector<int> dist_from_farthest(n, -1);
    bfs(n, adj, farthest_node1, dist_from_farthest);
    for(int i = 0; i < n; i++){
        cout << max(dist[i], dist_from_farthest[i]) << " ";
    }
    cout<<endl;
    return 0;
}