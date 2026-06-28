#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    if(!(cin>>n>>m))return 0;
    vector<vector<int>> dp(n+1, vector<int> (m+1, 1e9));
    for(int i = 1; i<=n;i++){
        for(int j = 1; j <= m; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int v = 1; v < i; v++){
                dp[i][j] = min(dp[i][j], dp[v][j] + dp[i-v][j] + 1);
            }
            for(int h = 1; h < j; h++){
                dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j-h] + 1);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}