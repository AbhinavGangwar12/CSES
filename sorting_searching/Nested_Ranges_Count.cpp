#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

struct Range{
    int l, r, in;
    bool operator<(const Range& other) const{
        if(l == other.l){
            return r > other.r;
        }
        return l < other.l;
    }
};

vector<vector<int>> get_ranges(const vector<vector<int>> &r, int n){
    vector<Range> ranges(n);
    vector<int> contains(n), contained(n);
    for(int i = 0; i < n; i++){
        int left = r[i][0], right = r[i][1];
        ranges[i].l = left;
        ranges[i].r = right;
        ranges[i].in = i;
    }
    sort(ranges.begin(), ranges.end());
    multiset<int> st;
    int min_right = 2e9;
    for(int i = n - 1; i >= 0; i--){
        if(ranges[i].r >= min_right){
            auto it = st.upper_bound(ranges[i].r);
            int val = it != st.end() ? distance(st.begin(), it) : 0 ;
            contains[ranges[i].in] = val;
        }
        st.insert(ranges[i].r);
        min_right = min(min_right, ranges[i].r);
    }
    st.clear();
    int max_right = 0;
    for(int i = 0; i < n; i++){
        if(ranges[i].r <= max_right){
            auto it = st.lower_bound(ranges[i].r);
            int val = it != st.end() ? distance(it, st.end()) : 0 ;
            contained[ranges[i].in] = val;
        }
        st.insert(ranges[i].r);
        max_right = max(max_right, ranges[i].r);
    }
    return {contains, contained};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    vector<vector<int>> r(n, vector<int> (2));
    for(int i = 0 ; i < n; i++){
        cin >> r[i][0] >> r[i][1];
    }
    vector<vector<int>> ans = get_ranges(r, n);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}