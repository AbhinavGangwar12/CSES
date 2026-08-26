#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        if(!(cin >> u >> v))return 0;
        adj[u-1].push_back(v-1);
        rev_adj[v-1].push_back(u-1);
    }
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    while(!q.empty()){
        int node = q.front();q.pop();
        if(visited[node])continue;
        visited[node] = true;
        for(int child: adj[node]){
            if(!visited[child]){
                q.push(child);
            }
        }
    }
    int unreachable_node = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            unreachable_node = i;
            break;
        }
    }
    if(unreachable_node != -1){
        cout<<"NO\n";
        cout<<1<<" "<<unreachable_node+1<<"\n";
    }
    else{
        q.push(0);
        visited.assign(n, false);
        while(!q.empty()){
            int node = q.front();q.pop();
            if(visited[node])continue;
            visited[node] = true;
            for(int child: rev_adj[node]){
                if(!visited[child]){
                    q.push(child);
                }
            }
        }
        unreachable_node = -1;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                unreachable_node = i;
                break;
            }
        }
        if(unreachable_node != -1){
            cout<<"NO\n";
            cout<<unreachable_node+1<<" "<<1<<"\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}