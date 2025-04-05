
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
        ll n,h;cin>>n>>h;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        auto predicate_func=[&](ll x)->bool{
            ll sum=0;
            for(int i=1;i<n;i++){
                if(a[i]-a[i-1]>=x)sum+=x;
                else sum+=a[i]-a[i-1];
            }
            return sum+x>=h;
        };
        ll low=1,high=1e18;
        while(low<=high){
            ll mid=(low+high)>>1;
            if(predicate_func(mid))high=mid-1;
            else low=mid+1;
        }
        cout<<low<<endl;
        
    }

    return 0;
}