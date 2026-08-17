#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// struct Answer{
//     int price;
//     int n_routes;
//     int minFlights;
//     int maxFlights;
// };
const int MOD = 1e9+7;
const long long INF = 1e18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<vector<pair<int, long long>>> routes(n);
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >>w;
        u--;v--;
        routes[u].push_back({v, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
  
    vector<long long> dist(n, INF);
    vector<int> ways(n, 0);
    vector<int> min_flights(n, 0);
    vector<int> max_flights(n, 0);

    dist[0] = 0;
    ways[0] = 1;
    q.push({0,0});
    while(!q.empty()){
        auto [w, node] = q.top();q.pop();
        if(w > dist[node])continue;
        for(auto [v,dx] : routes[node]){
            if(dist[node] + dx < dist[v]){
                dist[v] = dist[node] + dx;
                ways[v] = ways[node];
                max_flights[v] = max_flights[node] + 1;
                min_flights[v] = min_flights[node] + 1;
                q.push({dist[v], v});
            }
            else if(dist[node] + dx == dist[v]){
                ways[v] = (ways[node] + ways[v]) % MOD;
                min_flights[v] = min(min_flights[v], min_flights[node] + 1);
                max_flights[v] = max(max_flights[v], max_flights[node] + 1);
            }
        }
    }
    cout<<dist[n-1]<<" "<<ways[n-1]<<" "<<min_flights[n-1]<<" "<<max_flights[n-1]<<"\n";
    return 0;
}