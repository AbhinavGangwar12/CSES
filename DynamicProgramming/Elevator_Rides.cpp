#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin>>n>>m))return 0;
    vector<int> w(n);
    for(int i = 0; i<n ;i++){
        cin>>w[i];
    }
    vector<pair<int, long long>> dp((1<<n));
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<n); mask++){
        dp[mask] = {n + 1, 0};
        for(int i = 0; i < n ;i++){
            if(mask & (1 << i)){
                auto prev = dp[mask ^ (1 << i)];
                int rides = prev.first;
                long long weight = prev.second;
                if(weight + w[i] <= m)weight += w[i];
                else {
                    rides++;
                    weight = w[i];
                }
                if((rides < dp[mask].first) || (rides == dp[mask].first && weight < dp[mask].second)){
                    dp[mask] = {rides, weight};
                }
            }
        }
    }
    cout<<dp[(1<<n) - 1].first<<"\n";
    return 0;
}