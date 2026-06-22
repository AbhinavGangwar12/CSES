#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;
#define ll long long 
int main(){
    ll turns;
    cin>>turns;
    set<ll> s;
    for(int i=0;i<turns;i++){
        ll temp = 0;
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size()<<endl;
    return 0;
}