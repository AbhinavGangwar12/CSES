#include<iostream>
#include<vector>
#include<set>
#include<map>
#define ll long long int

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    if(!(cin >> n >> x))return 0;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<ll,ll> mp;
    ll left= 0;
    ll cnt = 0;
    for(ll right = 0; right < n; right++){
        mp[arr[right]]++;
        while(left < right && mp.size() > x){
            mp[arr[left]]--;
            if(mp[arr[left]] == 0){
                mp.erase(arr[left]);
            }
            left++;
        }
        cnt+= (right - left + 1);
    }
    cout<<cnt<<"\n";
    return 0;
}