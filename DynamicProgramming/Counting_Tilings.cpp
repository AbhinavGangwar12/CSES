#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

void get_next_mask(int curr_mask, int i, int next_mask, int n, vector<int> &next_masks) {
    if (i == n) {
        next_masks.push_back(next_mask);
        return;
    }
    if ((curr_mask & (1 << i)) != 0) {
        get_next_mask(curr_mask, i + 1, next_mask, n, next_masks);
    } 
    else {
        get_next_mask(curr_mask, i + 1, next_mask | (1 << i), n, next_masks);
        if (i + 1 < n && (curr_mask & (1 << (i + 1))) == 0) {
            get_next_mask(curr_mask, i + 2, next_mask, n, next_masks);
        }
    }
}

ll helper(int n, int m, int col, int mask, vector<vector<ll>> &dp) {
    if (col == m) {
        if (mask == 0) return 1;
        return 0;
    }
    if (dp[col][mask] != -1) return dp[col][mask];

    vector<int> next_masks;
    get_next_mask(mask, 0, 0, n, next_masks);
    
    ll ans = 0;
    for (auto nxt_mask : next_masks) { 
        ans = (ans + helper(n, m, col + 1, nxt_mask, dp)) % MOD;
    }
    
    return dp[col][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<ll>> dp(m + 1, vector<ll>(1 << n, -1));
    
    ll ans = helper(n, m, 0, 0, dp);
    
    cout << ans << "\n";
    
    return 0;
}