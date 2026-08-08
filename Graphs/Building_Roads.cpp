#include<iostream>
#include<vector>
using namespace std;

void route(const vector<vector<int>> &roads, vector<bool> &visited, int i){
    visited[i] = true;
    for(int j : roads[i]){
        if(!visited[j]){
            route(roads, visited, j);
        }
    }
    return;
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
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            ans.push_back(i);
            route(roads, visited, i);
        }
    }
    if(ans.size() == 1){
        cout<<0<<"\n";
        return 0;
    }
    cout<<ans.size()-1<<"\n";
    for(int i = 1; i < ans.size(); i++){
        cout<<ans[i-1]+1<<" "<<ans[i]+1<<"\n";
    }
    return 0;
}