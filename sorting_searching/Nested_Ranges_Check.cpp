#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
// Renamed from 'ranges' to 'Range' to avoid collision with C++20's std::ranges namespace
struct Range {
    int l, r, in;
    // overloads < operator for sorting
    bool operator<(const Range& other) const {
        if(l == other.l){
            return r > other.r;
        }
        return l < other.l;
    }
};
 
vector<vector<int>> check_ranges(const vector<vector<int>> &r, int n){
    vector<Range> range(n);
    vector<int> contains(n), contained(n);
    for(int i = 0 ; i < n; i++){
        int left = r[i][0], right = r[i][1];
        range[i].l = left;
        range[i].r = right;
        range[i].in = i;
    }
    sort(range.begin(), range.end());
    int min_end = 2e9;
    for(int i = n - 1; i >= 0; i--){
        if(range[i].r >= min_end){
            contains[range[i].in] = 1;
        }
        min_end = min(range[i].r, min_end);
    }
    int max_end = 0;
    for(int i = 0; i < n; i++){
        if(range[i].r <= max_end){
            contained[range[i].in] = 1;
        }
        max_end = max(range[i].r, max_end);
    }
    return { contains, contained };
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n)) return 0;
    
    vector<vector<int>> input_ranges(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> input_ranges[i][0] >> input_ranges[i][1];
    }
    
    vector<vector<int>> ans = check_ranges(input_ranges, n);
    for(int i = 0; i < n; i++){
        cout << ans[0][i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << ans[1][i] << " ";
    }
    return 0;
}