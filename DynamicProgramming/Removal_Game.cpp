#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
long long helper(const vector<long long> &arr, vector<vector<long long>> &dp, int i, int j){
    if(i > j)return 0;
    if(i == j)return arr[j];
    if(dp[i][j] != -1)return dp[i][j];
    long long left = arr[i] - helper(arr, dp, i+1, j);
    long long right = arr[j] - helper(arr, dp, i, j-1);
    return dp[i][j] = max(left,right);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))return 0;
    vector<long long> arr(n);
    long long total = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        total += arr[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    long long lead = helper(arr, dp, 0, n-1);
    cout<<(total + lead)/2LL<<"\n";
    return 0;
}