#include<iostream>
#define ll long long

using namespace std;

ll MOD = 1e9+7;

ll power(ll n, ll k){
    ll res = 1;
    while(k){
        if(k & 1)res = (res * n) % MOD;
        n = (n * n) % MOD;
        k >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    if(!(cin >> n))return 0;
    while(n--){
        ll n, k;
        cin >> n >> k;
        cout << power(n, k) % MOD<<"\n";
    }
    return 0;
}