#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<pair<int,int>> a(2*n);
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        a.push_back({x, 1});
        a.push_back({y, -1});
    }
    sort(a.begin(), a.end());
    int customers = 0, max_cust = 0;
    for(auto [temp, mark] : a){
        customers += mark;
        max_cust = max(max_cust, customers);
    }
    cout<<max_cust<<'\n';
    return 0;
}