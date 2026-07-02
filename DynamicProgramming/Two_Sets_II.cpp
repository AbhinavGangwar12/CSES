#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))return 0;
    int tot = n * (n+1) /2;
    if(tot%2!=0){
        cout<<0<<"\n";
        return 0;
    }
    int tar = tot /2;
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    for(int i = 0; i<n;i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i<n;i++){
        for(int j = 1; j <= tar; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= i){
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
    cout<<dp[n-1][tar]<<"\n";
    return 0;
}