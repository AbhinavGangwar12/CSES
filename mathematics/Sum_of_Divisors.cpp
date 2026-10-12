#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

// Safely compute (x * (x + 1) / 2) modulo MOD without overflow
long long sum_n(long long x) {
    long long a = x, b = x + 1;
    if (a % 2 == 0) {
        a /= 2;
    } else {
        b /= 2;
    }
    return (a % MOD) * (b % MOD) % MOD;
}

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long total_sum = 0;

    // Square Root Decomposition / Block Summation
    for (long long l = 1, r; l <= n; l = r + 1) {
        long long k = n / l;
        r = n / k; // Maximum r such that n / r == k

        // Sum of numbers from l to r
        long long range_sum = (sum_n(r) - sum_n(l - 1) + MOD) % MOD;
        
        // Multiply by k and add to total sum
        long long term = (range_sum * (k % MOD)) % MOD;
        total_sum = (total_sum + term) % MOD;
    }

    cout << total_sum << "\n";

    return 0;
}