#include<iostream>
#include<vector>
 
using namespace std;
 
bool dfs(const vector<vector<int>> &roads, vector<bool> &visited, vector<int> &path, int p, int u, int &start, int &end){
    visited[u] = true;
    for(int v : roads[u]){
        if(v == p)continue;
        if(visited[v]){
            start = v;
            end = u;
            return 1;
        }
        path[v] = u;
        if(dfs(roads, visited, path, u, v, start, end)){
            return 1;
        }
    }
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<int>> roads(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        roads[a-1].push_back(b-1);
        roads[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    vector<int> path(n, -1);
    int start = -1, end = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(roads, visited, path, -1, i, start, end)){
                break;
            }
        }
    }
    if(start == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> cycle;
    cycle.push_back(start);
    for(int v = end; v != start; v = path[v]){
        cycle.push_back(v);
    }
    cycle.push_back(start);
    cout<<cycle.size()<<"\n";
    for(int v : cycle){
        cout<<v+1<<" ";
    }
    cout<<"\n";
    return 0;
}