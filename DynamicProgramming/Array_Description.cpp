#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is_valid(int n, int m){return n >= 1 && n <= m;}
int MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin>>n>>m))return 0;
    vector<int> arr(n);
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i = 1; i<=m; i++){
        if(arr[0] == i || arr[0] == 0){
            dp[1][i] = 1;
        }
    }
    for(int i = 2; i<=n ;i++){
        for(int j = 1; j<=m; j++){
            if(arr[i-1] != 0 && arr[i-1] != j){
                dp[i][j] = 0;
                continue;
            }
            for(int prev = j-1; prev <= j+1; prev++){
                if(!is_valid(prev, m))continue;
                dp[i][j] = (dp[i][j] + dp[i-1][prev]) % MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<= m; i++){
        ans = (ans + dp[n][i]) % MOD;
    }
    cout<<ans<<"\n";
    return 0;
}