#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long

int main() {
    ll n;cin>>n;
    vector<ll>adj[n+1];
    for(ll i=2;i<=n;i++){
        ll u;cin>>u;
        adj[u].push_back(i);
    }
    for(auto it:adj)cout<<it.size()<<" ";
    cout<<endl;
    function<ll(ll,ll)>dfs=[&](ll node,ll par){
        ll cnt=1;
        if(adj[node].size()&1){
            ll maxi=0;
            for(auto child:adj[node]){
                if(child!=par){
                    maxi=max(dfs(child,node),maxi);
                }
            }
            cnt+=maxi;
        }

        return cnt;
    };
    cout<<dfs(1,0)<<endl;

    return 0;
}