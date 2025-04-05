#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long

int main(){
    ll t;cin >> t;
    while(t--){
    ll n,m;cin>>n>>m;
    map<ll,set<ll>>adj;
    for(int i=1;i<=n;i++)adj[i];
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    set<ll>st;
    queue<ll>q;
    for(auto it:adj){
        if(it.second.size()==0||(it.second.size()==1)){
                q.push(it.first);
                
        }
    }
    q.push(-1);
    ll cnt=0;
    while((!q.empty())&&m>0){
        ll u=q.front();q.pop();
        if(u==-1){m--;q.push(-1);continue;}
        if(adj[u].size()<=1&&st.find(u)==st.end()){st.insert(u);cnt++;}
        for(ll node:adj[u]){
            if(st.find(node)==st.end()){
                q.push(node);
                adj[node].erase(u);
            }
        }
        
    }

    cout<<n-cnt<<endl;
    }
    return 0;
}