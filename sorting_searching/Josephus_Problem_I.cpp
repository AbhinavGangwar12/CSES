#include<iostream>
#include<queue>
#define ll long long int 

using namespace std;

void solve(ll n){
    queue<ll> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    bool flag = false;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        if(flag){
            cout<<ele<<" ";
        }
        else{
            q.push(ele);
        }
        flag = !flag;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    solve(n);
    return 0;
}