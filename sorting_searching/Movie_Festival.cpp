#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<pair<int,int>> movies;
    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        movies.push_back({e,s});
    }
    sort(movies.begin(), movies.end());
    int ending = 0;
    int count = 0;
    for(auto [e,s] : movies){
        if(s >= ending){
            ending = e;
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}