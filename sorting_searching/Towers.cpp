#include<iostream>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if(!(cin >> n))return 0;
    multiset<int> st;
    for(int i = 0 ; i < n; i++){
        int element; 
        cin >> element;
        auto it = st.upper_bound(element);
        if(it != st.end()){
            st.erase(it);
        }
        st.insert(element);
    }
    
    cout<<st.size()<<endl;
    return 0;
}