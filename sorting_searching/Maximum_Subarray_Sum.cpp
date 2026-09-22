#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    long long maxi = -1e18;
    long long curr = 0;
    for(int i =0 ; i < n; i++){
        long long x;
        cin >> x;
        curr += x;
        maxi = max(maxi, curr);
        if(curr < 0)
            curr = 0;
    }
    cout<<maxi<<'\n';
    return 0;
}