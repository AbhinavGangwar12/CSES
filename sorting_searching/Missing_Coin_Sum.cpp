#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    long long current_sum = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > current_sum + 1) {
            break;
        }
        current_sum += x[i];
    }

    cout << current_sum + 1 << "\n";

    return 0;
}