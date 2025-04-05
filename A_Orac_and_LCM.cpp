
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    ll nums[200001];
    for(ll i=0; i<200001;i++)nums[i]=i;
    for(ll i=2; i*i<200001;i++){
        if(nums[i]==i){
            for(ll j=i*i;j<200001;j+=i)nums[j]=min(nums[j],i);
        
        }
    }
    // vector<ll>prime;
    // for(ll i=2; i<200001;i++)if(nums[i]==i)prime.push_back(i);
   
    // cout<<prime.size()<<endl;
    while(t--){
        ll n;cin>>n;
        ll a[n];
        for(int i=0; i<n; i++)cin>>a[i];
        map<ll,priority_queue<ll,vector<ll>,greater<ll>>>mp;
        
        for(ll i:a){
            while(i>1){
                ll p=nums[i];
                ll cnt=0;
                while(i%p==0){
                    i/=p;
                    cnt++;
                }
                mp[p].push(cnt);
            
            }
        }
        ll ans=1;
        for(auto i:mp){
            if(i.second.size()==n){
                i.second.pop();
                ans*=pow(i.first,i.second.top());
            }
            else if(i.second.size()==n-1){
                ans*=pow(i.first,i.second.top());
            }
        }
        
        cout<<ans<<endl;
        
        
    }

    return 0;
}