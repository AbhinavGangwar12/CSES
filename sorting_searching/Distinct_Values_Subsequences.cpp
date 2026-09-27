#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // dp[i] represents the number of valid index subsets using the first i elements
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // Base case: 1 way to form an empty subsequence
    unordered_map<long long, int> last_pos;

    for (int i = 1; i <= n; i++) {
        long long val = arr[i];

        // Double the number of valid subsequences from the previous step
        dp[i] = (2 * dp[i - 1]) % MOD;

        // If the element has appeared before at prev_idx, subtract overcounted subsequences
        if (last_pos.find(val) != last_pos.end()) {
            int prev_idx = last_pos[val];
            dp[i] = (dp[i] - dp[prev_idx] + MOD) % MOD;
        }

        // Update the last seen position of this value
        last_pos[val] = i;
    }

    // Subtract 1 to exclude the empty subsequence
    long long ans = (dp[n] - 1 + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}