#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define MOD 1000000007
#define SIZE 1000000

vector<int> fact(SIZE + 1);
vector<int> inv_fact(SIZE + 1);

int exp_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp) {
        if (exp & 1) {
            result = (result * 1LL * base) % mod;
        }
        base = (base * 1LL * base) % mod;
        exp >>= 1;
    }
    return result;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= SIZE; i++) {
        fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    }
    inv_fact[SIZE] = exp_pow(fact[SIZE], MOD - 2, MOD);
    for (int i = SIZE - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * 1LL * (i + 1)) % MOD;
    }
}

int main() {
    precompute();
    string s;
    cin >> s;

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int result = fact[s.size()];
    for (const auto& x : freq) {
        result = (result * 1LL * inv_fact[x.second]) % MOD;
    }

    cout << result << endl;
    return 0;
}
