#include<iostream>
#include<vector>
#include<map>
#define ll long long 

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    if(!(cin >> n))return 0;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<ll,ll> mp;
    mp[0]++;
    ll remainder = 0, cnt = 0;
    for(ll i = 0; i < n; i++){
        remainder = ((remainder + arr[i]) % n + n) % n;
        cnt += mp[remainder];
        mp[remainder]++;
    }
    cout<<cnt<<"\n";
    return 0;
}