#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isValid(const vector<long long>& arr, long long k, long long max_sum) {
    long long subarrays = 1;
    long long current_sum = 0;
    
    for (long long x : arr) {
        if (x > max_sum) return false;
        
        if (current_sum + x > max_sum) {
            subarrays++;
            current_sum = x;
        } else {
            current_sum += x;
        }
    }
    return subarrays <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    if (!(cin >> n >> k)) return 0;
    
    vector<long long> arr(n);
    long long low = 0, high = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        low = max(low, arr[i]);
        high += arr[i];
    }
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isValid(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } 
        else low = mid + 1;
    }
    
    cout << ans << "\n";
    return 0;
}