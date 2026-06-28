#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int helper(const string &n, const string &m, vector<vector<int>> &dp, int i, int j) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (n[i] == m[j]) {
        return dp[i][j] = helper(n, m, dp, i - 1, j - 1);
    }
    else {
        int insert_op = helper(n, m, dp, i, j - 1);
        int remove_op = helper(n, m, dp, i - 1, j);
        int replace_op = helper(n, m, dp, i - 1, j - 1);
        
        return dp[i][j] = 1 + min({insert_op, remove_op, replace_op});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> dp(n.length(), vector<int>(m.length(), -1));
    
    int res = helper(n, m, dp, n.length() - 1, m.length() - 1);
    cout << res << "\n";
    
    return 0;
}