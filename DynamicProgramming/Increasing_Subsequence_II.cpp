#include<iostream>
#include<vector>

using namespace std;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin>>n))return 0;
    vector<int> arr(n);
    for(int i = 0; i<n ;i++){
        cin>>arr[i];
    }
    vector<int> tail;
    int ans = 0;

    for(int i = 0; i<n; i++){
        if(tail.empty() || tail.back() < arr[i]){
            tail.push_back(arr[i]);
            ans = (ans + 1)%mod;
        }
        else{
            auto it = lower_bound(tail.begin(), tail.end(), arr[i]);
            if(*it != arr[i])
                ans = (ans + 1)%mod;
            *it = arr[i];
        }
    }
    cout<<(ans + n-1) % mod<<"\n";
    return 0;
}