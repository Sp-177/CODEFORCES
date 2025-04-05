#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(){
    long long n,m,q;
    cin>>n>>m>>q;
    long long t1,t2;cin>>t1>>t2;
    long long d;cin>>d;
    if(d>t1&&d>t2){
        cout<<(n-max(t1,t2))<<endl;
    }
    else if(d<t1&&d<t2){
        cout<<(-1+(min(t1,t2)))<<endl;
    }
    else{
        cout<<(max(t1,t2)-min(t1,t2))/2<<endl;
    }
    return ;
}
int main(){

    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
