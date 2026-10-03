#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t ;
    if(!(cin >> n >> t))return 0;
    vector<vector<int>> arr(n+1, vector<int> (2));
    for(int i = 1; i <=n; i++){
        cin>>arr[i][0];
        arr[i][1] = i;
    }
    sort(arr.begin(), arr.end());
    bool not_found = true;
    for(int i = 1; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            int k = j+1, l=n;
            while(k < l){
                long long cumsum = arr[i][0] + arr[j][0] + arr[k][0] + arr[l][0];
                if(cumsum == t){
                    cout<<arr[i][1]<<" "<<arr[j][1]<<" "<<arr[k][1]<<" "<<arr[l][1]<<"\n";
                    not_found = false;
                    break;
                }
                else if(cumsum > t){
                    l--;
                }
                else k++;
            }
            if(!not_found)break;
        }
        if(!not_found)break;
    }
    if(not_found)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}