#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long largest = arr[n-1];
    long long sum = accumulate(arr.begin(), arr.end() - 1, 0LL);
    if(largest <= sum){
        cout<<sum+largest<<"\n";
    }
    else{
        cout<<2 * largest<<"\n";
    }
    return 0;
}