
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        if(a==b){
            cout<<"infinity"<<endl;
        }
        else{
            ll dif=a-b,ans=0;
            for(ll i=1;i*i<=dif;i++){
                if(dif%i==0){
                    if(i>b)ans++;
                    if(dif/i!=i&&(dif/i>b))ans++;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}