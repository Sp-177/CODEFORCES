
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    cin>>t;
    while(t--){
        int n,m,l,r;cin>>n>>m>>l>>r;
        if(r<=0){
            cout<<-(m)<<" "<<0<<endl;
        }
        else{
            if(m>r){
                cout<<-(m-r)<<" "<<r<<endl;
            }
            else{
                cout<<0<<"  "<<m<<endl;
            }
        }

    }

    return 0;
}