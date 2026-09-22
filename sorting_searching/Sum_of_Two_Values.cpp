#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long sum;
    if (!(cin >> n >> sum)) return 0;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    while (left < right) {
        long long current_sum = (long long)arr[left].first + arr[right].first;
        
        if (current_sum == sum) {
            cout << arr[left].second << " " << arr[right].second << "\n";
            return 0;
        } else if (current_sum < sum) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}