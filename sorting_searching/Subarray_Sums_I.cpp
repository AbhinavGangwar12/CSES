#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    long long t;
    if(!(cin >> n >> t))return 0;
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long sum = 0;
    long long left = 0, right = 0;
    long long cnt = 0;
    while(right < n){
        sum += arr[right];
        while (sum > t && left <= right) {
            sum -= arr[left];
            left++;
        }
        if (sum == t) {
            cnt++;
        }
        right++;
    }
    cout<<cnt<<"\n";
    return 0;
}