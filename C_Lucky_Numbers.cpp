#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long ways = (1LL << n+1) - 2;
    cout<<ways<<endl;
    return 0;
}