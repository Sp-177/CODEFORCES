#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long

int main() {
    ll n;cin>>n;
    
    vector<ll>adj[n+1];
    for(ll i=2;i<=n;i++){
        ll u;cin >> u;
        adj[u].push_back(i);
    }
    ll ans[n+1];

    function<bool(ll,ll)>dfs=[&](ll node,ll par){
        int cnt=0;
        for(ll i:adj[node]){
            if(i!=par){
                if(dfs(i,node))cnt++;
            }
        }
       ans[node]=cnt;
        if(adj[node].size()==0){ans[node]=3;return true;}
        return false;
    };
    dfs(1,0);
    bool check=true;
    for(ll i=1;i<=n;i++){
        if(ans[i]<3){check=false;break;}
    }
    if(check)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}