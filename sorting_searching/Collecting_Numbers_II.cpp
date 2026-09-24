#include<iostream>
#include<vector>
#include<set>

using namespace std;

int rounds(const vector<int> &arr){
    int round = 1;
    for(int i = 2; i < arr.size(); i++){
        if(arr[i] < arr[i-1]){
            round++;
        }
    }
    return round;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if(!(cin >> n >> m))return 0;
    vector<int> arr(n+1), pos(n+1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        pos[x] = i;
    }
    int round_ = rounds(pos);
    while(m--){
        int a, b;
        cin >> a>> b;

        int x = arr[a];
        int y = arr[b];
        if(x == y){
            cout<<round_<<endl;
            continue;
        }
        set<int> s;
        if(x > 1)s.insert(x);
        if(x < n)s.insert(x+1);
        if(y > 1)s.insert(y);
        if(y < n)s.insert(y+1);

        for(int k : s){
            if(pos[k] < pos[k-1]){
                round_--;
            }
        }
        swap(arr[a], arr[b]);
        pos[arr[a]] = a;
        pos[arr[b]] = b;
        
        for(int k : s){
            if(pos[k] < pos[k-1]){
                round_++;
            }
        }
        cout<<round_<<endl;
    }
    return 0;
}