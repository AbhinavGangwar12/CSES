#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    if(!(cin >> n >> t))return 0;
    vector<vector<int>> arr(n, vector<int> (2));
    for(int i = 0; i < n; i++){
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    sort(arr.begin(), arr.end());
    bool not_found = true;
    for(int left = 0; left < n-2; left++){
        int mid = left + 1, right = n-1;
        while(mid < right){
            long long cumsum = arr[left][0] + arr[mid][0] + arr[right][0];
            if(cumsum == t){
                cout<<arr[left][1]+1<<" "<<arr[mid][1]+1<<" "<<arr[right][1]+1<<"\n";
                not_found = false;
                break;
            }
            else if(cumsum > t){
                right--;
            }
            else mid++;
        }
        if(!not_found)break;
    }
    if(not_found)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}