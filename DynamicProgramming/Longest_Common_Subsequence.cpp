#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int helper(const vector<int> &a,const vector<int> &b,vector<vector<int>> &dp, int i, int j){
    if(i < 0 || j < 0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(a[i] == b[j]){
        
        return dp[i][j] = helper(a, b, dp, i-1, j-1) + 1;
    }
    return dp[i][j] = max(helper(a,b,dp,i-1,j), helper(a,b,dp,i,j-1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin>>n>>m))return 0;
    vector<int> a(n), b(m);
    for(int i = 0 ; i < n; i++){cin>>a[i];}
    for(int i = 0 ; i < m; i++){cin>>b[i];}
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int res = helper(a, b, dp, n-1, m-1);
    cout<<res<<"\n";
    int i = n-1, j = m-1;
    vector<int> lcs;
    while(i >= 0 && j >= 0) {
        if(a[i] == b[j]) {
            lcs.push_back(a[i]);
            i--;j--;
        } 
        else {
            int up = helper(a, b, dp, i - 1, j);
            int left = helper(a, b, dp, i, j - 1);
            
            if(up > left) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    for(int k = 0; k < lcs.size(); k++) {
        cout << lcs[k] << (k == lcs.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}