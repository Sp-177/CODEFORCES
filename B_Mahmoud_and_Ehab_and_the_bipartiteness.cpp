
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int  main(){
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t=1;
    // cin>>t;
    while(t--){
        ll  n;cin>>n;
        map<ll ,vector<ll >>adj;
       
        for(ll  i=0;i<n-1;i++){
            ll  u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
           
        }
       ll  cnt1=0,cnt0=0;
        function<void(ll ,ll ,ll )>dfs=[&](ll  node,ll  par,ll  col){
           if(col)cnt1++;
              else cnt0++;
            for(auto child:adj[node]){
                if(child!=par){
                    dfs(child,node,col^1);
                }
            }
        };
        dfs(1,-1,0);
       ll  ans=cnt0*cnt1-n+1;
        cout<<ans<<endl;


    }

    return 0;
}