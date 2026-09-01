#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    // pair<int,int> is used to store the adjacent node and the edge index
    vector<vector<pair<int,int>>> adj(MAXN);
    vector<bool> used(MAXM);
    vector<int> degrees(MAXN, 0);
    vector<int> head(MAXN);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degrees[u]++;
        degrees[v]++;
    }

    for(int i = 0; i < n; i++){
        if(degrees[i] % 2 != 0){
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> st;
    vector<int> circuit;
    st.push_back(0);
    while(!st.empty()){
        int u = st.back();
        int found = false;
        while(head[u] < adj[u].size()){
            auto [v, edge_index] = adj[u][head[u]];
            head[u]++;
            if(!used[edge_index]){
                used[edge_index] = true;
                st.push_back(v);
                found = true;
                break;
            }
        }
        if(!found){
            circuit.push_back(u);
            st.pop_back();
        }
    }
    if(circuit.size() != m + 1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for(int i = circuit.size() - 1; i >= 0; i--){
        cout << circuit[i] + 1 << " ";
    }
    return 0;
}