#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

pair<int,int> bfs(const vector<vector<int>> &tree, int node, int n){
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    int f_node = node;
    int max_dist = 0;
    while(!q.empty()){
        auto u = q.front();q.pop();
        if(dist[u] > max_dist){
            f_node = u;
            max_dist = dist[u];
        }
        for(int v : tree[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {f_node, max_dist};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<vector<int>> tree(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    auto [f_node, d] = bfs(tree, 0, n);
    auto [ temp , diameter] = bfs(tree, f_node, n);
    cout<<diameter<<"\n";
    return 0;
}