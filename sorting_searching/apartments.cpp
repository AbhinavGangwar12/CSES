#include<bits/stdc++.h>
using namespace std;

const int s = 2e5+1;
int n,m,k,desire[s],available[s];

int main(){
    cin >> n >> m >>k;
    for(int i = 0;i<n;i++){
        cin >> desire[i];
    }
    for(int i = 0;i<m;i++){
        cin >> available[i];
    }
    sort(available,available+m);
    sort(desire,desire+n);
    int count = 0;
    // this is uses merge sort's merge function approach
    int i = 0,j = 0;
    while(i<n){
        if(j<m && desire[i]-k > available[j])j++;
        else if(j<m && (desire[i]-k <= available[j] && desire[i]+k >= available[j])){
            count++;
            i++;
            j++;
        }
        else i++;
    }
    cout<<count<<endl;
    return 0;
}