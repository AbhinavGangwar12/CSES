// #include<iostream>
// #include<map>
// #include<vector>
// #include<stack>
// #include<algorithm>

// using namespace std;

// #define ll long long 
// #define MOD 998244353

// int main(){
//     ll n = 0;
//     cin>>n;
//     vector<pair<ll,ll>> arr;
//     for(ll i =0;i<n;i++){
//         ll temp;
//         cin>>temp;
//         temp %= MOD;
//         arr.push_back({temp,i});
//     }
//     sort(arr.begin(),arr.end());
//     map<int,pair<ll,ll>> mp;
//     ll back = 0,front = 0;
//     while(front < n){
//         do{
//             front++;
//         }while(front < n && arr[front].first == arr[back].first);
//         if(front >= n)break;
//         mp[arr[back].first] = {arr[back].second,arr[front-1].second};
//         back = front;
//     }
//     vector<pair<ll,ll>> merges;
//     for(auto x : mp){
//         merges.push_back(x.second);
//     }
//     sort(merges.begin(),merges.end());
    
//     stack<pair<ll,ll>> st;
//     st.push(merges[0]);
//     for(int i = 1;i<merges.size();i++){
//         auto t = st.top();
//         if(t.second < merges[i].first)st.push(merges[i]);
//         else if(t.second >= merges[i].first ){
//             t.second = merges[i].second;
//             st.pop();
//             st.push(t);
//         }
//     }
//     ll int ans = ( 1LL << (st.size()%MOD))%MOD;
//     cout<<ans<<endl;

//     return 0;
// }



#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define ll long long 
#define MOD 998244353

// Function to compute (base^pow) % mod using modular exponentiation
ll mod_exp(ll base, ll pow, ll mod) {
    ll result = 1;
    while (pow) {
        if (pow & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        pow >>= 1;
    }
    return result;
}

int main() {
    ll n = 0;
    cin >> n;
    vector<pair<ll, ll>> arr;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        temp %= MOD; // Ensure temp is within MOD
        arr.push_back({temp, i});
    }
    
    sort(arr.begin(), arr.end());
    
    map<ll, pair<ll, ll>> mp;
    ll back = 0, front = 0;
    
    while (front < n) {
        do {
            front++;
        } while (front < n && arr[front].first == arr[back].first);
        
        if (front >= n) break;
        
        mp[arr[back].first] = {arr[back].second, arr[front - 1].second};
        back = front;
    }
    
    vector<pair<ll, ll>> merges;
    for (auto x : mp) {
        merges.push_back(x.second);
    }
    
    sort(merges.begin(), merges.end());
    
    stack<pair<ll, ll>> st;
    st.push(merges[0]);
    
    for (int i = 1; i < merges.size(); i++) {
        auto t = st.top();
        if (t.second < merges[i].first)
            st.push(merges[i]);
        else if (t.second >= merges[i].first) {
            t.second = merges[i].second;
            st.pop();
            st.push(t);
        }
    }
    
    ll num_intervals = st.size();
    ll ans = mod_exp(2, num_intervals, MOD); // Compute (2^num_intervals) % MOD
    cout << ans << endl;
    
    return 0;
}
