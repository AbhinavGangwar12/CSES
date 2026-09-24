#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<int, int> last_pos; // Stores the last seen index of each song ID safely
    int max_len = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        int x;
        cin >> x;

        // If the song has been seen and is inside the current window
        if (last_pos.count(x) && last_pos[x] >= left) {
            left = last_pos[x] + 1; // Move the left boundary past the previous occurrence
        }

        // Update the last seen position of the song
        last_pos[x] = right;

        // Calculate the length of the current unique sequence
        max_len = max(max_len, right - left + 1);
    }

    cout << max_len << "\n";

    return 0;
}