#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }

            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }

            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}