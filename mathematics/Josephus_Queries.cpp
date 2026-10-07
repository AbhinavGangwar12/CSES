#include <iostream>

using namespace std;

long long solve(long long n, long long k) {
    if (n == 1) return 1;
    
    long long half = (n + 1) / 2;
    
    // If the k-th removal happens in the current pass
    if (k <= half) {
        if (2 * k > n) return (2 * k) % n;
        return 2 * k;
    }
    
    // Otherwise, it happens in the remaining children
    if (n % 2 == 1) {
        // n is odd, remaining children are 3, 5, 7, ...
        long long res = solve(n / 2, k - half);
        return 2 * res + 1;
    } else {
        // n is even, remaining children are 1, 3, 5, ...
        long long res = solve(n / 2, k - half);
        return 2 * res - 1;
    }
}

int main() {
    // Optimize standard input/output streams for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    if (!(cin >> q)) return 0;
    
    while (q--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    
    return 0;
}