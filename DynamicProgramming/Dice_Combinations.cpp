#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int helper(int sum, vector<int>& dp) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;

    if (dp[sum] != -1) return dp[sum];

    long long ways = 0;
    for (int dice = 1; dice <= 6; dice++) {
        ways = (ways + helper(sum - dice, dp)) % MOD;
    }

    return dp[sum] = ways;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << helper(n, dp) << "\n";

    return 0;
}
