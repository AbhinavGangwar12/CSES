#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool dfs(const vector<vector<int>> &edges, vector<int> &state, vector<int> &parent, int u, stack<int> &order){
    state[u] = 1;
    for(auto v : edges[u]){
        if(state[v] == 0){
            parent[v] = u;
            if(dfs(edges, state, parent, v, order)){
                return true;
            }
        }
        else if(state[v] == 1)
            return true;
    }
    state[u] = 2;
    order.push(u);
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges[u-1].push_back(v-1);
    }
    vector<int> state(n, 0);
    vector<int> parent(n, -1);
    stack<int> order;
    for(int i = 0; i < n; i++){
        if(state[i] == 0){
            if(dfs(edges, state, parent, i, order)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    while(!order.empty()){
        cout<<order.top()+1<<" ";
        order.pop();
    }
    cout<<"\n";
    return 0;
}