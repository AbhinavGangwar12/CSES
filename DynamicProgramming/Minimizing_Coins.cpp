#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int helper(const vector<int> &arr, vector<int> &dp, int target){
    if(target == 0) return 0;
    if(target < 0) return INF;
    if(dp[target] != -1) return dp[target];
    
    int ans = INF;
    for(int c: arr){
        int res = helper(arr, dp, target - c);
        if(res != INF){
            ans = min(ans, 1 + res);
        }
    }
    return dp[target] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum;
    if (!(cin >> n >> sum)) return 0;
    
    vector<int> arr(n);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> dp(sum + 1, -1);
    int res = helper(arr, dp, sum);
    
    if(res != INF){
        cout << res << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
    
    return 0;
}