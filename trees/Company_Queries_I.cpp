#include<iostream>
#include<vector>

using namespace std;

const int LOGN = 20;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    if(!(cin >> n >> q))return 0;
    vector<vector<int>> up(n + 1, vector<int> (LOGN, -1));
    for(int i = 2; i<=n ;i ++){
        int p;
        cin>>p;
        up[i][0] = p;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < LOGN; j++){
            if(up[i][j-1] != -1){
                up[i][j] = up[up[i][j-1]][j-1];
            }
        }
    }
    while(q--){
        int node, k;
        cin >> node >> k;
        for(int j = 0; j < LOGN; j++){
            if((k >> j) & 1){
                node = up[node][j];
                if(node == -1)break;
            }
        }
        cout<<node<<endl;
    }
    return 0;
}