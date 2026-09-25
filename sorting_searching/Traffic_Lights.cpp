#include<iostream>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    if(!(cin >> n >> t))return 0;
    multiset<int> lengths;
    set<int> pos;
    pos.insert(0);
    pos.insert(n);
    lengths.insert(n);  
    for(int i = 0; i < t; i++){
        int x;
        cin >> x;
        auto it = pos.upper_bound(x);
        int right = *it;
        int left = *prev(it);
        lengths.erase(lengths.find(right - left));
        lengths.insert(x-left);
        lengths.insert(right - x);
        pos.insert(x);
        cout<<*lengths.rbegin()<<" ";
    }
    return 0;
}