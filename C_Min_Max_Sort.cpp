
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
     ll a[n],ind[n];
     for(ll i=0;i<n;i++){cin>>a[i];ind[a[i]]=i;}
     ll ans=0;
     bool toggled=false;
     ll  mid=n/2,sum=n+1;
     ll c1=-1,c2=-1;
     if(n&1){
        c1=ind[mid+1];
     }
     while(mid>0){
        ll cmpl=sum-mid;
        if(toggled){ans++;mid--;continue;}
        ll ind1=ind[mid];
        ll ind2=ind[cmpl];
        // cout<<c1<<" "<<c2<<endl<<mid<<" "<<cmpl<<endl<<ind1<<" "<<ind2<<endl;
        if(c1==-1&&c2==-1 &&(ind1>ind2)){toggled=true;}
        else if(c1!=-1&&c2==-1&&(ind1>ind2||c1<ind1||c1>ind2)){toggled=true;}
        else if(c1!=-1&&c2!=-1)if(((ind1>ind2)||(c1<ind1)||(c2>ind2)||(c2<ind1)||(c1>ind2))) {toggled=true;}
        if(toggled)ans++;
        c1=ind1,c2=ind2;
        mid--;

     }
     cout<<ans<<endl;       
    }

    return 0;
}