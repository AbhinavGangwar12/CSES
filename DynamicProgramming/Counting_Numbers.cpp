#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
long long dp[20][11][2][2]; 

long long helper(const string &num, int n, int x, bool is_leading_zeros, bool tight){
    if(n == 0)
        return 1;
        
    if(dp[n][x][is_leading_zeros][tight] != -1) 
        return dp[n][x][is_leading_zeros][tight];
        
    int lb = 0;
    int ub = tight ? num[num.length() - n] - '0' : 9;
    long long ans = 0;
    
    for(int dig = lb; dig <= ub; dig++){
        if(dig == x && is_leading_zeros == 0)
            continue;
        ans += helper(num, n-1, dig, is_leading_zeros && (dig == 0), tight & (dig == ub));
    }
    
    return dp[n][x][is_leading_zeros][tight] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b;
    if(!(cin >> a >> b)) return 0;
    
    string B = to_string(b);
    memset(dp, -1, sizeof(dp));
    long long larger = helper(B, B.length(), 10, 1, 1);
    
    long long smaller = 0;
    if (a > 0) {
        string A = to_string(a - 1);
        memset(dp, -1, sizeof(dp));
        smaller = helper(A, A.length(), 10, 1, 1);
    }
    
    cout << larger - smaller << "\n";
    
    return 0;
}