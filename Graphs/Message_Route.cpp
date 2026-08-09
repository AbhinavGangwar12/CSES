#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void dijkstra(const vector<vector<pair<int,int>>> &roads, vector<int> &dist,vector<int> &parent, int start){
    dist[start] = 1;
    parent[start] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        pair<int,int> current = pq.top();
        int node = current.second;
        int distance = current.first;
        pq.pop();
        if(distance > dist[node])continue;
        for(auto &neighbor : roads[node]){
            int next_node = neighbor.first;
            int weight = neighbor.second;
            if(dist[node] + weight < dist[next_node]){
                dist[next_node] = dist[node] + weight;
                parent[next_node] = node;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<pair<int,int>>> roads(n);
    int max_distance = 2*1e9+7;
    for(int i = 0; i < m ; i++){
        int a, b;
        cin >> a >> b;
        roads[a-1].push_back({b-1, 1});
        roads[b-1].push_back({a-1, 1});
    }
    vector<int> dist(n, max_distance);
    vector<int> parent(n, -1);
    dijkstra(roads, dist, parent, 0);
    if(dist[n-1]  == max_distance){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<dist[n-1]<<"\n";
        vector<int> path;
        for(int i = n-1; i != -1; i = parent[i]){
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++){
            cout<<path[i]+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}