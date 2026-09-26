#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    map<int,int> mp;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long tot = 0;
    int left = 0;
    for(int right = 0; right < n; right++){
        if(mp.count(arr[right]) && mp[arr[right]] >= left)
            left = mp[arr[right]] + 1;
        mp[arr[right]] = right;
        tot += (right - left + 1);
    }
    cout<<tot<<endl;
    return 0;
}