#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin>>n))return 0;
    vector<int> arr(n);
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }

    vector<int> left(n, -1), right(n, -1);
    stack<int> st;

    for(int i = 0; i< n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            left[i] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){st.pop();}
    for(int i = n-1; i > -1; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            right[i] = st.top();
        }
        st.push(i);
    }
    vector<pair<int,int>> mounts;
    for(int i = 0; i<n; i++){
        mounts.push_back({arr[i], i});
    }
    sort(mounts.rbegin(), mounts.rend());
    vector<int> dp(n, 1);
    int max_mounts = 0;
    for(int i = 0; i<n ; i++){
        int curr = mounts[i].second;

        int left_ = left[curr];
        int right_ = right[curr];

        int left_max = (left_ != -1) ?dp[left_] : 0;
        int rightt_max = (right_ != -1) ?dp[right_] : 0;

        dp[curr] = 1 + max(left_max, rightt_max);
        max_mounts = max(max_mounts, dp[curr]);
    }
    cout<<max_mounts<<"\n";
    return 0;
}