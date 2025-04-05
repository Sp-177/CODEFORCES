
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
        int n;cin>>n;
        ll a[n+1];
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)cin>>a[i];
        map<ll,vector<ll>>adj;
        for(int i=0;i<n-1;i++){
            ll u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<ll,ll>ans;
        function <void(int ,int)>dfs=[&](int node,int par){
            map<ll,ll>freq;
            freq[a[par]]++;
            freq[a[node]]++;
            for(auto x:adj[node]){
                if(x!=par){
                    freq[a[x]]++;
                    if(freq[a[x]]>=2)ans[a[x]]++;
                    dfs(x,node);
                }
            }
            if(freq[a[node]]>=2)ans[a[node]]++;
            if(freq[a[par]]>=2)ans[a[par]]++;

        };
        dfs(1,0);
        for(int i=1;i<=n;i++){if(ans[i])cout<<1;else cout<<0;}
        cout<<"\n";
    }

    return 0;
}