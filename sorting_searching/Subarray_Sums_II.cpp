#include<iostream>
#include<vector>
#include<map>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    if(!(cin >> n >> t))return 0;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<ll,ll> mp;
    ll prefix = 0, cnt = 0;
    mp[0]++;
    for( ll &ele : arr){
        prefix+= ele;
        if(mp.find(prefix - t) != mp.end()){
            cnt+= mp[prefix-t];
        }
        mp[prefix]++;
    }
    cout<<cnt<<"\n";
    return 0;
}