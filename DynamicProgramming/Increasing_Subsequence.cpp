#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

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
    for(int i = 0; i<n ; i++){
        if(tail.empty() || tail.back() < arr[i]){
            tail.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(tail.begin(), tail.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout<<tail.size()<<"\n";
    return 0;
}