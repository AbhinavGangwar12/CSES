#include<iostream>
#include<set>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c;
    if(!(cin >> n >> c))return 0;
    multiset<int> st;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.insert(x);
    }
    for(int i = 0; i < c; i++){
        int ticket;
        cin >> ticket;
        auto it = st.upper_bound(ticket);
        if(it == st.begin()){
            cout<<-1<<"\n";
        }
        else{
            it--;
            cout<<*it<<"\n";
            st.erase(it);
        }
    }
    return 0;
}