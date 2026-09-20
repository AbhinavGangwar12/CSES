#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cap;
    if (!(cin >> n >> cap)) return 0;

    vector<int> bacche(n);
    for (int i = 0; i < n; i++) {
        cin >> bacche[i];
    }

    sort(bacche.begin(), bacche.end());

    int i = 0, j = n - 1;
    int gondolas = 0;

    while (i <= j) {
        if (i == j) {
            gondolas++;
            break;
        }

        if (bacche[i] + bacche[j] <= cap) {
            i++;
            j--;
        } else {
            j--;
        }
        gondolas++;
    }

    cout << gondolas << '\n';
    return 0;
}