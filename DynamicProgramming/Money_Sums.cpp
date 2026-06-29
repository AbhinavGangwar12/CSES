#include <iostream>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

void helper(const vector<int> &arr, vector<vector<char>> &visited, set<int> &ans, int i, int current_sum) {
    if (i < 0) {
        if (current_sum > 0) {
            ans.insert(current_sum);
        }
        return;
    }

    if (visited[i][current_sum]) return;
    
    visited[i][current_sum] = true;

    helper(arr, visited, ans, i - 1, current_sum);

    helper(arr, visited, ans, i - 1, current_sum + arr[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_sum += arr[i];
    }
    vector<vector<char>> visited(n, vector<char>(max_sum + 1, false));
    set<int> ans;

    helper(arr, visited, ans, n - 1, 0);
    cout << ans.size() << "\n";
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << *it << (next(it) == ans.end() ? "" : " ");
    }
    cout << "\n";

    return 0;
}