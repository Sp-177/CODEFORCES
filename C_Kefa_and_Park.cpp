#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long

int main() {
    ll n,m;cin>>n>>m;
    ll arr[n+1];
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr[0]=0;
    vector<ll>adj[n+1];
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<ll(ll ,ll,ll)>dfs=[&](ll node,ll par,ll num_cats){
        if(num_cats>m)return 0LL;
        if(adj[node].size()==1&&adj[node][0]==par){
            // cout<<node<<" "<<num_cats<<" "<<endl;
            if((num_cats+arr[node])<=m)return 1LL;
            return 0LL;
        }
        ll ans=0LL;
        for(ll it :adj[node]){
            if(it!=par)ans+=dfs(it,node,arr[node]==0?0:num_cats+1);
        }
        return ans;
    };
    cout<<dfs(1,0,0)<<endl;
    return 0;
}