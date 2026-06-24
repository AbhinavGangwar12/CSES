#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

long long dp[MAXN][2];

void precompute() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i][0] = (4LL * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + 2LL * dp[i-1][1]) % MOD;
    }
}

void solve(int t) {
    while (t--) {
        int x;
        cin >> x;
        cout << (dp[x][0] + dp[x][1]) % MOD << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute(); 
    
    int t;
    if (cin >> t) {
        solve(t);
    }
    
    return 0;
}