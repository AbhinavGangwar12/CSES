#include<iostream>
#include<queue>
#define ll long long int 

using namespace std;

void solve(ll n,ll k){
    queue<ll> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout<<cnt<<" ";
        if(cnt = k){
            cout<<ele<<" ";
        }
        else{
            q.push(ele);
        }
        cnt = (cnt + 1) % q.size();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    if(!(cin >> n >> k))return 0;
    solve(n, k);
    return 0;
}