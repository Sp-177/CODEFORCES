
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
     ll n;cin>>n;
     ll pos=LLONG_MIN,neg=LLONG_MIN;
     ll ans=0;
     for(int i=0;i<n;i++){
        ll x;cin>>x;
        if(x>0){
            pos=max(pos,x);
            if(neg!=LLONG_MIN){ans+=neg;neg=LLONG_MIN;}
        }else{
            neg=max(neg,x);
            if(pos!=LLONG_MIN){ans+=pos;pos=LLONG_MIN;}
        }
     }
     if(pos==LLONG_MIN)ans+=neg;
     else ans+=pos;
     cout<<ans<<endl;
    }

    return 0;
}