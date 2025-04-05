
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
   map<ll,priority_queue<ll>>mp;
   for(int i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    mp[x].push(y);
   }ll ans=0;
   for(auto i:mp){
    ll num=i.first;
    for(int i=0;i<num&&mp[num].size();i++){
        ans+=mp[num].top();
        mp[num].pop();
    }
   }
    cout<<ans<<endl;
    
    }

    return 0;
}