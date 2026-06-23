#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    if (!(cin >> n >> x)) return 0;
    
    vector<int> price(n);
    vector<int> pages(n);
    
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    
    cout << dp[x] << "\n";
    
    return 0;
}