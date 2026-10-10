#include<iostream>

using namespace std;
const int MAX = 1000005;
int divisors[MAX];

void precompute(){
    for(int i = 1; i < MAX; i++){
        for(int j = i; j < MAX; j+=i){
            divisors[j]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    precompute();
    while(n--){
        int x;
        cin >> x;
        cout<<divisors[x]<<"\n";
    }
    return 0;
}
