#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    if(!(cin >> n >> m >> k)) return 0;
    vector<vector<pair<int, long long>>> edges(n);
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[u-1].push_back({v-1, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<int> counts(n , 0);
    vector<long long> ans;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(counts[u] >= k)continue;
        counts[u]++;
        if(u == n-1){
            ans.push_back(d);
            if(ans.size() == k) break;
        }
        for(auto [v, w] : edges[u]){
            if(counts[v] < k){
                pq.push({d + w, v});
            }
        }
    }
    for(int i = 0; i < k; i++){
        cout << ans[i] << " ";
    }
    return 0;
}