#include<iostream>
#include<vector>

using namespace std;
const int MAX_LOG = 30;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if(!(cin >> n >> q))return 0;
    vector<vector<int>> parents(n+1 , vector<int>(MAX_LOG, -1));
    for(int i = 1; i<=n ;i++){
        int p;
        cin >> p;
        parents[i][0] = p;
    }
    for(int j = 1; j<MAX_LOG;j++){
        for(int i = 1; i <= n; i++){
            parents[i][j] = parents[ parents[i][j-1] ][j-1];
        }
    }
    for(int i = 0; i < q; i++){
        int a, k;
        cin >> a >> k;
        for(int j = 0; j < MAX_LOG; j++){
            if(k & (1 << j)){
                a = parents[a][j];
            }
        }
        cout << a << "\n";
    }
    return 0;
}