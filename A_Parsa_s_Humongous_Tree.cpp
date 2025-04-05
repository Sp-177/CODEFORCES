#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long

int main() {
    ll n;cin>>n;
    pair<ll,ll>arr[n+1];
    for(ll i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    vector<ll>adj[n+1];
    for(ll i=1;i<n;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return 0;
}