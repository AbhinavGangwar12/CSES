#include<iostream>
#include<vector>
// #include<algorithm>

using namespace std;
const int MOD = 1e9 + 7;

int helper(const vector<int> &coins, vector<int> &dp, int target){
    if(target < 0)return 0;
    if(target == 0)return 1;
    if(dp[target] != -1)return dp[target];
    long long ways = 0;
    for(int c: coins){
        ways = (ways + helper(coins, dp, target-c)) % MOD;
    }
    return dp[target] = ways;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sum;
    if(!(cin>>n>>sum))return 0;
    vector<int> coins(n);
    for(int i = 0 ; i< n; i++){
        cin>>coins[i];
    }
    vector<int> dp(sum+1, -1);
    int res = helper(coins, dp, sum);
    cout<<dp[sum]<<"\n";
    return 0;
}