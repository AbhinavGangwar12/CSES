#include<iostream>
using namespace std;

const int MAX = 1000005;
int freq[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    int maxi = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        freq[x]++;
        maxi = max(maxi, x);
    }
    for(int i = maxi; i >= 1; i--){
        int cnt =  0;
        for(int j = i; j <= maxi; j += i){
            cnt += freq[j];
            if(cnt >= 2){
                cout<<i<<"\n";
                return 0;
            }
        }
    }
    return 0;
}