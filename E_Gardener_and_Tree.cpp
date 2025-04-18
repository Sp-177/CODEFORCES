#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll         long long

int main(){
    ll t;cin >> t;
    while(t--){
         ll n,k;cin >> n >> k;
         unordered_map  <ll,vector<ll>>adj,mp;
         for(int i = 0; i <n-1;i++){
                ll u,v;cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
         }
         for(int i=1;i<=n;i++){
               mp[adj[i].size()].push_back(i);
         }
            ll cnt = n,cnt_edges = 1;
         while(k-- &&cnt>=0){
            cnt-=mp[cnt_edges].size();
            cnt_edges++;
         }
         cout<<cnt<<endl;

    }   

    return 0;
}