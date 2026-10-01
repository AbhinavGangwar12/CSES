#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long helper(const vector<long long> &k, int n, long long t, long long mid){
    long long prods = 0;
    for(int i = 0; i < n; i++){
        prods += mid / k[i];
        if(prods >= t)
            break;
    }
    return prods;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long t;
    if(!(cin >> n >> t))return 0;

    vector<long long> k(n);
    long long min_k = 2e9;
    for(int i = 0; i < n; i++){
        cin >> k[i];
        min_k = min(min_k, k[i]);
    }
    long long low = 1, high = min_k * t, ans = high;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        int prods = helper(k, n, t, mid);
        if(prods >= t){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}