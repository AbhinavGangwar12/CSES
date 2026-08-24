#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<int> t(n+1);
    vector<int> indegree(n+1, 0);
    vector<vector<int>> adj_rev(n+1);

    for(int i = 1; i <= n; i++){
        cin >> t[i];
        indegree[t[i]]++;
        adj_rev[t[i]].push_back(i);
    }
    queue<int> Q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        indegree[t[u]]--;
        if(indegree[t[u]] == 0){
            Q.push(t[u]);
        }
    }

    int current_cid = 1;
    vector<bool> in_cycle(n+1, false);
    vector<int> cycle_id(n+1, 0);
    vector<int> cycle_len;
    cycle_len.push_back(0); // 1-based indexing for cycle IDs

    for(int i = 1; i <= n; i++){
        if(indegree[i] > 0 && !in_cycle[i]){
            int curr = i;
            int len = 0;
            while(!in_cycle[curr]){
                in_cycle[curr] = true;
                cycle_id[curr] = current_cid;
                curr = t[curr];
                len++;
            }
            cycle_len.push_back(len);
            current_cid++;
        }
    }

    vector<int> depth(n+1, 0);
    vector<int> root(n +1, 0);
    for(int i = 1; i <= n; i++){
        if(in_cycle[i]){
            Q.push(i);
            root[i] = i;
        }
    }
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v : adj_rev[u]){
            if(!in_cycle[v]){
                depth[v] = depth[u] + 1;
                root[v] = root[u];
                Q.push(v);
            }
        }
    }

    for(int i = 1; i<=n; i++){
        int total_steps = depth[i] + cycle_len[cycle_id[root[i]]];
        cout << total_steps <<(i == n ? "" : " ");
    }
    return 0;
}