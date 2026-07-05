#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> L(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            L[i] = (long long)(i + 1) * arr[i];
        } else {
            int j = st.top();
            L[i] = L[j] + (long long)(i - j) * arr[i];
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();
    vector<long long> R(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            R[i] = (long long)(n - i) * arr[i];
        } else {
            int j = st.top();
            R[i] = R[j] + (long long)(j - i) * arr[i];
        }
        st.push(i);
    }

    long long max_floors = -1;
    int best_idx = 0;
    for (int i = 0; i < n; i++) {
        long long total = L[i] + R[i] - arr[i];
        if (total > max_floors) {
            max_floors = total;
            best_idx = i;
        }
    }

    vector<int> ans(n);
    ans[best_idx] = arr[best_idx];
    
    for (int i = best_idx - 1; i >= 0; i--) {
        ans[i] = min(arr[i], ans[i + 1]);
    }

    for (int i = best_idx + 1; i < n; i++) {
        ans[i] = min(arr[i], ans[i - 1]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}