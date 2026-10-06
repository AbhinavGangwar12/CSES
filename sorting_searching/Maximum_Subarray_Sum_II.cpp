#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Compute prefix sums
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + x[i];
    }

    multiset<long long> window;
    long long max_sum = -1e18; // Initialize with a very small number

    for (int j = 1; j <= n; j++) {
        // Add the new valid prefix sum P[j - a] to the window
        if (j - a >= 0) {
            window.insert(pref[j - a]);
        }
        // Remove the prefix sum P[j - b - 1] that is now too far away
        if (j - b - 1 >= 0) {
            window.erase(window.find(pref[j - b - 1]));
        }
        // If the window is not empty, the maximum subarray ending at j-1 
        // using a prefix sum in the range is pref[j] - min_prefix_sum
        if (!window.empty()) {
            max_sum = max(max_sum, pref[j] - *window.begin());
        }
    }

    cout << max_sum << "\n";

    return 0;
}