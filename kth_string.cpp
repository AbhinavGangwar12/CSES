#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

#define MOD 1000000007
#define SIZE 1000000

vector<int> fact(SIZE+1);
vector<int> inv_fact(SIZE+1);

int exp_pow(int base,int pow,int mod){
    int result = 1;
    while(pow){
        if(pow&1)result = (result * 1LL * base)%MOD;
        pow >>= 1;
        base = (base * 1LL * base)%MOD;
    }
    return result;
}

void pre_compute(){
    fact[0] = 1;
    for(int i = 1;i<=SIZE;i++){
        fact[i] = (fact[i-1] * 1LL * i)%MOD;
    }
    inv_fact[SIZE] = exp_pow(fact[SIZE],MOD-2,MOD);
    for(int i = SIZE-1;i>=0;i--){
        inv_fact[i-1] = (inv_fact[i] * 1LL * i)%MOD;
    }
}


int main(){
    pre_compute();
    
    string s;
    cin>>s;
    int k;
    cin>>k;
    
    string ans = "";
    map<char,int> mp;
    set<char> st(s.begin(),s.end());

    sort(s.begin(),s.end());
    for(const auto& x : s){
        mp[x]++;
    }
    int size = s.size();
    int idx = 0;
    auto itr = mp.begin();
    while(k>1){
        start:
            int possible = fact[size-1];
            if(itr->second == 0){
                st.erase(itr->first);
                mp.erase(itr);
            }
            for(auto x : mp){
                if(x.first == itr->first)possible = (possible * 1LL*inv_fact[itr->second-1])%MOD;
                else possible = (possible * 1LL * inv_fact[x.second])%MOD;
            }

            if(possible >= k){
                ans.push_back(itr->first);
            }
            else {
                k -= possible;
                itr = st.upper_bound(itr->first);
                goto start;

            }
    }

    return 0;
}