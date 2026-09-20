#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> app(n);
    vector<int> apt(m);

    for (int i = 0; i < n; i++) {
        cin >> app[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apt[i];
    }

    sort(app.begin(), app.end());
    sort(apt.begin(), apt.end());

    int i = 0, j = 0, count = 0;

    while (i < n && j < m) {
        if (abs(app[i] - apt[j]) <= k) {
            i++;
            j++;
            count++;
        }
        else if (apt[j] < app[i] - k) {
            j++;
        }
        else {
            i++;
        }
    }

    cout << count << "\n";
    return 0;
}