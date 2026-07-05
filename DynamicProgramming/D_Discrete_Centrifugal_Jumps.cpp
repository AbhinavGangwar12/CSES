#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const long long INF = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    if(!(cin >> n)) return 0;
    
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    stack<long long> max_left, min_left;
    vector<long long> dp(n, INF);
    dp[0] = 0; // ✅ FIX 1: Base case

    for(long long i = 0; i < n; i++){
        // Valley Jumps
        while(!max_left.empty()){
            long long tallest = max_left.top();
            dp[i] = min(dp[i], dp[tallest] + 1);
            if(arr[tallest] == arr[i]){
                max_left.pop();
                break;
            }
            if(arr[tallest] > arr[i]){
                break;
            }
            max_left.pop();
        }
        
        // Hill Jumps
        while(!min_left.empty()){
            long long smallest = min_left.top();
            dp[i] = min(dp[i], dp[smallest] + 1);
            if(arr[smallest] == arr[i]){
                min_left.pop();
                break;
            }
            if(arr[smallest] < arr[i]){
                break;
            }
            min_left.pop();
        }
        
        max_left.push(i);
        min_left.push(i);
    }
    
    cout << dp[n-1] << "\n";
    return 0;
}