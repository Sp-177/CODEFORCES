
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
ll ask(ll l,ll r){cout<<"xor "<<l<<' '<<r<<endl; cin>>r; cout.flush();return r;}
void sol(ll low, ll high,set<ll>&ans){
    if(low>high)return;
    if(low==high){
        if(ask(low,high))ans.insert(low);
        return;
    }
    ll mid=(low+high)/2ULL;
    ll temp1=ask(low,mid);
    ll temp2=ask(mid+1ULL,high);
    if(temp1&&temp2==0ULL){
        sol(low,mid,ans);
    }
    else if(temp2&&temp1==0ULL){
        sol(mid+1ULL,high,ans);
    }
    else{
        sol(low,mid,ans);
        sol(mid+1ULL,high,ans);
    }
}
int main(){
ll t;
cin>>t;
while(t--){
    ll n;cin>>n;
    set<ll>ans;
    sol(1ULL,n,ans);
    cout<<"ans ";for(auto i:ans)cout<<i<<" ";
    cout<<endl;
}

return 0;
}
