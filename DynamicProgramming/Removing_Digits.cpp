#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e6+7;

int helper(vector<int> &dp, int sum){
    if(sum < 0)return INF;
    if(sum == 0)return 0;
    if(dp[sum] != -1)return dp[sum];
    int temp = sum;
    int ans = INF;
    while(temp){
        int digit = temp % 10;
        temp /= 10;
        if(digit)ans = min(ans, 1 + helper(dp, sum - digit));
    }
    return dp[sum] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))return 0;
    vector<int> dp(n+1, -1);
    int res = helper(dp, n);
    cout<<res<<"\n";
    return 0;
}