
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll mod=1e9+7;
    auto bp=[&](ll  x,ll  y)->ll {
        ll  ans=1;
        while(y){
            if(y&1)ans=(ans*x);
            ans%=mod;
            x*=x;
            x%=mod;
            y>>=1;
        }
        return ans;
    };
    ll t=1;
    // cin>>t;
    while(t--){
      ll n,m,k;cin>>n>>m>>k;
      if(k==1||k>n){
        cout<<bp(m,n)<<endl;
      }
        else if(k==n){
            cout<<bp(m,((n+1)>>1))<<endl;
        }
        else if(k&1){
            cout<<bp(m,2)<<endl;
        }
        else{
            cout<<bp(m,1)<<endl;
        }
    }

    return 0;
}