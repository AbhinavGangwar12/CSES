#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int l = arr[n/2];
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(arr[i] - l);
    }
    cout<<ans<<endl;
    return 0;
}