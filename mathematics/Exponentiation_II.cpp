#include<iostream>
#define ll long long

using namespace std;

const ll MOD = 1e9+7;
const ll MOD_MINUS_1 = 1e9 + 6;

ll power(ll n, ll k, const ll MOD){
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
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = power(b,c, MOD_MINUS_1);
        ans = power(a, ans, MOD);
        cout<<ans<<"\n";
    }
    return 0;
}