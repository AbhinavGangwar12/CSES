#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const long long INF = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<pair<int, long long>>> edges(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    vector<vector<long long>> dist(n+1, vector<long long>(2, INF));
    dist[1][0] = 0;
    using State = tuple<long long, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        auto [d, u, used] = pq.top(); pq.pop();
        if(d > dist[u][used]) continue;
        for(auto [v, w] : edges[u]){
            if(d + w < dist[v][used]){
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
            if(!used){
                if(d + w/2 < dist[v][1]){
                    dist[v][1] = d + w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
    cout<< dist[n][1]<<"\n";
    return 0;
}